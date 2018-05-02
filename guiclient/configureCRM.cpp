/*
 * This file is part of the xTuple ERP: PostBooks Edition, a free and
 * open source Enterprise Resource Planning software suite,
 * Copyright (c) 1999-2018 by OpenMFG LLC, d/b/a xTuple.
 * It is licensed to you under the Common Public Attribution License
 * version 1.0, the full text of which (including xTuple-specific Exhibits)
 * is available at www.xtuple.com/CPAL.  By using this software, you agree
 * to be bound by its terms.
 */

#include "configureCRM.h"

#include <QMessageBox>
#include <QSqlError>
#include <QVariant>

#include <metasql.h>

#include "guiclient.h"
#include "mqlutil.h"
#include "errorReporter.h"

configureCRM::configureCRM(QWidget* parent, const char* name, bool /*modal*/, Qt::WindowFlags fl)
    : XAbstractConfigure(parent, fl)
{
  XSqlQuery configureconfigureCRM;
  setupUi(this);

  if (name)
    setObjectName(name);

  _nextInNumber->setValidator(omfgThis->orderVal());
  _nextAcctNumber->setValidator(omfgThis->orderVal());
  _nextProjectNumber->setValidator(omfgThis->orderVal());
  _nextTaskNumber->setValidator(omfgThis->orderVal());

  configureconfigureCRM.exec( "SELECT orderseq_number AS innumber "
          "  FROM orderseq"
          " WHERE (orderseq_name='IncidentNumber');" );
  if (configureconfigureCRM.first())
    _nextInNumber->setText(configureconfigureCRM.value("innumber"));
    
  configureconfigureCRM.exec( "SELECT orderseq_number AS acnumber "
          "  FROM orderseq"
          " WHERE (orderseq_name='CRMAccountNumber');" );
  if (configureconfigureCRM.first())
    _nextAcctNumber->setText(configureconfigureCRM.value("acnumber"));

  configureconfigureCRM.exec( "SELECT orderseq_number AS prjnumber "
          "  FROM orderseq"
          " WHERE (orderseq_name='ProjectNumber');" );
  if (configureconfigureCRM.first())
    _nextProjectNumber->setText(configureconfigureCRM.value("prjnumber"));

  configureconfigureCRM.exec( "SELECT orderseq_number AS tsknumber "
          "  FROM orderseq"
          " WHERE (orderseq_name='TaskNumber');" );
  if (configureconfigureCRM.first())
    _nextTaskNumber->setText(configureconfigureCRM.value("tsknumber"));

  QString metric = _metrics->value("CRMAccountNumberGeneration");
  if (metric == "M")
    _acctGeneration->setCurrentIndex(0);
  else if (metric == "A")
    _acctGeneration->setCurrentIndex(1);
  else if (metric == "O")
    _acctGeneration->setCurrentIndex(2);

  metric = _metrics->value("ProjectNumberGeneration");
  if (metric == "M")
    _projectGeneration->setCurrentIndex(0);
  else if (metric == "A")
    _projectGeneration->setCurrentIndex(1);
  else if (metric == "O")
    _projectGeneration->setCurrentIndex(2);

  metric = _metrics->value("TaskNumberGeneration");
  if (metric == "M")
    _taskGeneration->setCurrentIndex(0);
  else if (metric == "A")
    _taskGeneration->setCurrentIndex(1);
  else if (metric == "O")
    _taskGeneration->setCurrentIndex(2);
    
  _useProjects->setChecked(_metrics->boolean("UseProjects"));
  _autoCreate->setChecked(_metrics->boolean("AutoCreateProjectsForOrders"));
  _accountChangeLog->setChecked(_metrics->boolean("AccountChangeLog"));
  _addressChangeLog->setChecked(_metrics->boolean("AddressChangeLog"));
  _contactChangeLog->setChecked(_metrics->boolean("ContactChangeLog"));
  _opportunityChangeLog->setChecked(_metrics->boolean("OpportunityChangeLog"));
  _requireProjectAssignment->setChecked(_metrics->boolean("RequireProjectAssignment"));
  _projectWarningDays->setValue(_metrics->value("ProjectDueDateWarning").toInt());
  _requireUniqueEmails->setChecked(_metrics->boolean("EnforceUniqueContactEmails"));
  _defaultEmailopt->setChecked(_metrics->boolean("DefaultEmailOptIn"));
  _defaultAddropt->setChecked(_metrics->boolean("DefaultAddressOptIn"));

  if (! _metrics->value("DefaultAddressCountry").isEmpty())
    _country->setText(_metrics->value("DefaultAddressCountry"));

  _strictCountries->setChecked(_metrics->boolean("StrictAddressCountry"));
  _strictCountries->setEnabled(! _strictCountries->isChecked());
  if (! _strictCountries->isChecked())
  {
    connect(_strictCountries, SIGNAL(toggled(bool)), this, SLOT(sStrictCountryChanged(bool)));
  }

  _incidentsPublicShow->setChecked(_metrics->boolean("IncidentsPublicPrivate"));
  _incidentsPublicDefault->setChecked(_metrics->boolean("IncidentPublicDefault"));

  if (_metrics->boolean("EnableBatchManager"))
  {
    _incdtEmailProfile->populate("SELECT ediprofile_id, ediprofile_name "
                                 "FROM xtbatch.ediprofile "
                                 "WHERE (ediprofile_type='email');");
    _incdtEmailProfile->setId(_metrics->value("CRMIncidentEmailProfile").toInt());
    _incdtCreated->setChecked(_metrics->boolean("CRMIncidentEmailCreated"));
    _incdtAssigned->setChecked(_metrics->boolean("CRMIncidentEmailAssigned"));
    _incdtStatus->setChecked(_metrics->boolean("CRMIncidentEmailStatus"));
    _incdtUpdated->setChecked(_metrics->boolean("CRMIncidentEmailUpdated"));
    _incdtComments->setChecked(_metrics->boolean("CRMIncidentEmailComments"));
  }
  else
  {
    _incdtEmailProfileLit->hide();
    _incdtEmailProfile->hide();
    _incdtDelGroup->hide();
  }

  configureconfigureCRM.exec("SELECT * FROM status WHERE (status_type='INCDT') ORDER BY status_seq;");
  configureconfigureCRM.first();
  _new->setText(configureconfigureCRM.value("status_color"));
  configureconfigureCRM.next();
  _feedback->setText(configureconfigureCRM.value("status_color"));
  configureconfigureCRM.next();
  _confirmed->setText(configureconfigureCRM.value("status_color"));
  configureconfigureCRM.next();
  _assigned->setText(configureconfigureCRM.value("status_color"));
  configureconfigureCRM.next();
  _resolved->setText(configureconfigureCRM.value("status_color"));
  configureconfigureCRM.next();
  _closed->setText(configureconfigureCRM.value("status_color"));

  adjustSize();
}

configureCRM::~configureCRM()
{
    // no need to delete child widgets, Qt does it all for us
}

void configureCRM::languageChange()
{
    retranslateUi(this);
}

bool configureCRM::sSave()
{
  emit saving();

  const char *numberGenerationTypes[] = { "M", "A", "O" };

  XSqlQuery configq;
  configq.prepare( "SELECT setNextIncidentNumber(:innumber);" );
  configq.bindValue(":innumber", _nextInNumber->text().toInt());
  configq.exec();
  
  if (QString(numberGenerationTypes[_acctGeneration->currentIndex()]) != "M" && _nextAcctNumber->text().toInt() < 1)
    _nextAcctNumber->setText("1");
  if (QString(numberGenerationTypes[_projectGeneration->currentIndex()]) != "M" && _nextProjectNumber->text().toInt() < 1)
    _nextProjectNumber->setText("1");
  if (QString(numberGenerationTypes[_taskGeneration->currentIndex()]) != "M" && _nextTaskNumber->text().toInt() < 1)
    _nextTaskNumber->setText("1");

  configq.prepare( "SELECT setNextCRMAccountNumber(:acnumber);" );
  configq.bindValue(":acnumber", _nextAcctNumber->text().toInt());
  configq.exec();

  configq.prepare( "SELECT setNextProjectNumber(:prjnumber);" );
  configq.bindValue(":prjnumber", _nextProjectNumber->text().toInt());
  configq.exec();

  configq.prepare( "SELECT setNextTaskNumber(:tsknumber);" );
  configq.bindValue(":tsknumber", _nextTaskNumber->text().toInt());
  configq.exec();

  _metrics->set("CRMAccountNumberGeneration", QString(numberGenerationTypes[_acctGeneration->currentIndex()]));
  _metrics->set("ProjectNumberGeneration", QString(numberGenerationTypes[_projectGeneration->currentIndex()]));
  _metrics->set("TaskNumberGeneration", QString(numberGenerationTypes[_taskGeneration->currentIndex()]));
  
  _metrics->set("UseProjects", _useProjects->isChecked());
  _metrics->set("AutoCreateProjectsForOrders", (_autoCreate->isChecked() && _useProjects->isChecked()));
  _metrics->set("AccountChangeLog", _accountChangeLog->isChecked());
  _metrics->set("AddressChangeLog", _addressChangeLog->isChecked());
  _metrics->set("ContactChangeLog", _contactChangeLog->isChecked());
  _metrics->set("OpportunityChangeLog", _opportunityChangeLog->isChecked());
  _metrics->set("RequireProjectAssignment", _requireProjectAssignment->isChecked());
  _metrics->set("ProjectDueDateWarning", _projectWarningDays->value());

  if (_country->isValid())
    _metrics->set("DefaultAddressCountry", _country->currentText());
  else
    _metrics->set("DefaultAddressCountry", QString(""));

  _metrics->set("StrictAddressCountry", _strictCountries->isChecked());
  
  _metrics->set("IncidentsPublicPrivate", _incidentsPublicShow->isChecked());
  _metrics->set("IncidentPublicDefault", _incidentsPublicDefault->isChecked());

  if (!_metrics->boolean("EnforceUniqueContactEmails") && (_requireUniqueEmails->isChecked()))
  {
    // Check for existing duplicated Contact email addresses if switching on
    QString usql = "SELECT EXISTS(SELECT 1 FROM cntcteml "
                   "GROUP BY cntcteml_email "
                   "HAVING count(*) > 1) AS result;";
    configq.exec(usql);
    if (configq.first() && (configq.value("result").toBool()))
    {
      QMessageBox::warning(this, tr("Unique Emails"),
      tr("You cannot enable unique email addresses on contacts "
         "when duplicates exist.  Please first remove all "
         "duplicate email addresses on contacts, then enable this setting."));
      _requireUniqueEmails->setChecked(false);
      return false;
    }
  }
  _metrics->set("EnforceUniqueContactEmails", _requireUniqueEmails->isChecked());
  _metrics->set("DefaultEmailOptIn", _defaultEmailopt->isChecked());
  _metrics->set("DefaultAddressOptIn", _defaultAddropt->isChecked());

  if (_metrics->boolean("EnableBatchManager"))
  {
    _metrics->set("CRMIncidentEmailProfile", _incdtEmailProfile->id());
    _metrics->set("CRMIncidentEmailCreated"   , _incdtCreated->isChecked());
    _metrics->set("CRMIncidentEmailAssigned"  , _incdtAssigned->isChecked());
    _metrics->set("CRMIncidentEmailStatus"    , _incdtStatus->isChecked());
    _metrics->set("CRMIncidentEmailUpdated"   , _incdtUpdated->isChecked());
    _metrics->set("CRMIncidentEmailComments"  , _incdtComments->isChecked());
  }

  configq.prepare("UPDATE status SET status_color = :color "
            "WHERE ((status_type='INCDT') "
            " AND (status_code=:code));");
  configq.bindValue(":code", "N");
  configq.bindValue(":color", _new->text());
  configq.exec();
  configq.bindValue(":code", "F");
  configq.bindValue(":color", _feedback->text());
  configq.exec();
  configq.bindValue(":code", "C");
  configq.bindValue(":color", _confirmed->text());
  configq.exec();
  configq.bindValue(":code", "A");
  configq.bindValue(":color", _assigned->text());
  configq.exec();
  configq.bindValue(":code", "R");
  configq.bindValue(":color", _resolved->text());
  configq.exec();
  configq.bindValue(":code", "L");
  configq.bindValue(":color", _closed->text());
  configq.exec();

  return true;
}

/* TODO: introduced option in 3.4.0beta2.
   deprecate it in the future with strict as the standard.
 */
void configureCRM::sStrictCountryChanged(bool p)
{
  if (p)
  {
    bool mqlloaded;
    MetaSQLQuery mql = mqlLoad("crm", "strictcountrycheck", &mqlloaded);
    if (! mqlloaded)
    {
      QMessageBox::critical(this, tr("Query Not Found"),
                            tr("<p>The application could not find the MetaSQL "
                               "query crm-strictcountrycheck."));
      _strictCountries->setChecked(false);
      return;
    }

    ParameterList params;
    params.append("count");
    XSqlQuery activeq = mql.toQuery(params);

    params.append("showAll");
    XSqlQuery allq = mql.toQuery(params);

    if (activeq.first())
    {
      int result = activeq.value("counter").toInt();
      if (result > 0)
      {
        QMessageBox::warning(this, tr("Invalid Countries"),
                             tr("<p>The database contains invalid countries in "
                                "active records, such as addresses and open "
                                "sales orders. Please correct these records "
                                "before turning on strict country checking. "
                                "You may download and install the "
                                "fixCountry.gz package "
                                "to help with this task."));
        _strictCountries->setChecked(false);
        return;
      }
    }
    else if (ErrorReporter::error(QtCriticalMsg, this, tr("Error Confirming Country Information"),
                                  activeq, __FILE__, __LINE__))
    {
      return;
    }

    if (allq.first())
    {
      int result = allq.value("counter").toInt();
      if (result > 0)
      {
        QMessageBox::StandardButton answer =
          QMessageBox::question(this, tr("Invalid Countries"),
                                tr("<p>The database contains invalid countries "
                                   "in historical records, such as closed "
                                   "sales orders and posted invoices. If you "
                                   "do not correct these countries before "
                                   "turning on strict country checking, you "
                                   "may lose country values if you open these "
                                   "documents and save them again. You may "
                                   "download and install the fixCountry.gz "
                                   "package to help update your records."
                                   "<p>Are you sure you want to turn on "
                                   "strict country checking?"),
                               QMessageBox::Yes | QMessageBox::No,
                               QMessageBox::No);
        if (answer == QMessageBox::No)
        {
          _strictCountries->setChecked(false);
          return;
        }
      }
    }
    else if (ErrorReporter::error(QtCriticalMsg, this, tr("Error Confirming Country Information"),
                                  allq, __FILE__, __LINE__))
    {
      return;
    }
  }
}
