/*
 * This file is part of the xTuple ERP: PostBooks Edition, a free and
 * open source Enterprise Resource Planning software suite,
 * Copyright (c) 1999-2012 by OpenMFG LLC, d/b/a xTuple.
 * It is licensed to you under the Common Public Attribution License
 * version 1.0, the full text of which (including xTuple-specific Exhibits)
 * is available at www.xtuple.com/CPAL.  By using this software, you agree
 * to be bound by its terms.
 */

#include "checkFormat.h"

#include <QMessageBox>
#include <QSqlError>
#include <QVariant>

checkFormat::checkFormat(QWidget* parent, const char* name, bool modal, Qt::WFlags fl)
    : XDialog(parent, name, modal, fl)
{
  setupUi(this);

  connect(_buttonBox, SIGNAL(accepted()), this, SLOT(sSave()));

  _report->setCurrentIndex(-1);
}

checkFormat::~checkFormat()
{
  // no need to delete child widgets, Qt does it all for us
}

void checkFormat::languageChange()
{
  retranslateUi(this);
}

enum SetResponse checkFormat::set(const ParameterList &pParams)
{
  XDialog::set(pParams);
  QVariant param;
  bool     valid;

  param = pParams.value("form_id", &valid);
  if (valid)
  {
    _formid = param.toInt();
    populate();
  }

  param = pParams.value("mode", &valid);
  if (valid)
  {
    if (param.toString() == "new")
    {
      _mode = cNew;
    }
    else if (param.toString() == "edit")
    {
      _mode = cEdit;
    }
    else if (param.toString() == "view")
    {
      _mode = cView;

      _name->setEnabled(FALSE);
      _report->setEnabled(FALSE);
      _buttonBox->clear();
      _buttonBox->addButton(QDialogButtonBox::Close);
    }
  }

  return NoError;
}

void checkFormat::sSave()
{
  XSqlQuery checkSave;
  if (_name->text().trimmed().length() == 0)
  {
    QMessageBox::warning( this, tr("Check Format Name is Invalid"),
                          tr("You must enter a valid name for this Check Format.") );
    _name->setFocus();
    return;
  }

  if (_report->currentIndex() == -1)
  {
    QMessageBox::warning( this, tr("Report is Invalid"),
                          tr("You must enter a select report for this Check Format.") );
    _report->setFocus();
    return;
  }

  if (_mode == cNew)
  {
    checkSave.exec("SELECT NEXTVAL('form_form_id_seq') AS _form_id");
    if (checkSave.first())
      _formid = checkSave.value("_form_id").toInt();
    else if (checkSave.lastError().type() != QSqlError::NoError)
    {
      systemError(this, checkSave.lastError().databaseText(), __FILE__, __LINE__);
      return;
    }

    checkSave.prepare( "INSERT INTO form "
               "(form_id, form_name, form_descrip, form_report_name, form_key) "
               "VALUES "
               "(:form_id, :form_name, :form_descrip, :form_report_name, 'Chck');" );
  }
  else if (_mode == cEdit)
    checkSave.prepare( "UPDATE form "
               "SET form_name=:form_name, form_descrip=:form_descrip,"
               "    form_report_name=:form_report_name "
               "WHERE (form_id=:form_id);" );

  checkSave.bindValue(":form_id", _formid);
  checkSave.bindValue(":form_name", _name->text());
  checkSave.bindValue(":form_descrip", _descrip->text());
  checkSave.bindValue(":form_report_name", _report->code());
  checkSave.exec();
  if (checkSave.lastError().type() != QSqlError::NoError)
  {
    systemError(this, checkSave.lastError().databaseText(), __FILE__, __LINE__);
    return;
  }

  done(_formid);
}

void checkFormat::populate()
{
  XSqlQuery checkpopulate;
  checkpopulate.prepare( "SELECT form_name, form_descrip, form_report_name "
       	     "FROM form "
	     "WHERE (form_id=:form_id);" );
  checkpopulate.bindValue(":form_id", _formid);
  checkpopulate.exec();
  if (checkpopulate.first())
  {
    _name->setText(checkpopulate.value("form_name").toString());
    _descrip->setText(checkpopulate.value("form_descrip").toString());
    _report->setCode(checkpopulate.value("form_report_name").toString());
  }
  else if (checkpopulate.lastError().type() != QSqlError::NoError)
  {
    systemError(this, checkpopulate.lastError().databaseText(), __FILE__, __LINE__);
    return;
  }
}
