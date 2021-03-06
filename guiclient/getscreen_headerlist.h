// generated 2009-04-30
// grep "public X[Dialog,Widget]" *.h | awk -F : '{print "#include \""$1"\""}' > getscreen_headerlist.h
#include "absoluteCalendarItem.h"
#include "account1099.h"
#include "accountingPeriod.h"
#include "accountingPeriods.h"
#include "accountingYearPeriod.h"
#include "accountingYearPeriods.h"
#include "accountNumber.h"
#include "accountNumbers.h"
#include "addPoComment.h"
#include "addresses.h"
#include "address.h"
#include "adjustmentTrans.h"
#include "adjustInvValue.h"
#include "allocateARCreditMemo.h"
#include "allocateReservations.h"
#include "apAccountAssignment.h"
#include "apAccountAssignments.h"
#include "apCreditMemoApplication.h"
#include "apOpenItem.h"
#include "applyAPCreditMemo.h"
#include "applyARCreditMemo.h"
#include "applyDiscount.h"
#include "apWorkBench.h"
#include "arAccountAssignment.h"
#include "arAccountAssignments.h"
#include "archRestoreSalesHistory.h"
#include "arCreditMemoApplication.h"
#include "arOpenItem.h"
#include "arWorkBench.h"
#include "assessFinanceCharges.h"
#include "assignClassCodeToPlannerCode.h"
#include "assignItemToPlannerCode.h"
#include "assignLotSerial.h"
#include "bankAccount.h"
#include "bankAccounts.h"
#include "bankAdjustmentEditList.h"
#include "bankAdjustment.h"
#include "bankAdjustmentType.h"
#include "bankAdjustmentTypes.h"
#include "bom.h"
#include "bomItem.h"
#include "bomList.h"
#include "budgets.h"
#include "buyCard.h"
#include "calendar.h"
#include "calendars.h"
#include "cashReceipt.h"
#include "cashReceiptItem.h"
#include "cashReceiptMiscDistrib.h"
#include "cashReceiptsEditList.h"
#include "changePoitemQty.h"
#include "changeWoQty.h"
#include "characteristicAssignment.h"
#include "characteristic.h"
#include "characteristicPrice.h"
#include "characteristics.h"
#include "checkFormat.h"
#include "checkFormats.h"
#include "check.h"
#include "classCode.h"
#include "classCodes.h"
#include "classCodeTax.h"
#include "closePurchaseOrder.h"
#include "closeWo.h"
#include "commentType.h"
#include "commentTypes.h"
#include "companies.h"
#include "company.h"
#include "configureCC.h"
#include "configureCRM.h"
#include "configureEncryption.h"
#include "configureGL.h"
#include "configureIE.h"
#include "configureIM.h"
#include "configureMS.h"
#include "configurePD.h"
#include "configurePO.h"
#include "configureSO.h"
#include "configureSearchPath.h"
#include "configureWO.h"
#include "confirmAchOK.h"
#include "contact.h"
#include "contacts.h"
#include "contactMerge.h"
#include "contract.h"
#include "contracts.h"
#include "copyBOM.h"
#include "copyBudget.h"
#include "copyContract.h"
#include "copyItem.h"
#include "copyPurchaseOrder.h"
#include "copySalesOrder.h"
#include "copyTransferOrder.h"
#include "correctProductionPosting.h"
#include "costCategories.h"
#include "costCategory.h"
#include "costingElements.h"
#include "countries.h"
#include "country.h"
#include "countSlip.h"
#include "countTag.h"
#include "countTagList.h"
#include "createCountTagsByItem.h"
#include "createCountTagsByParameterList.h"
#include "createCycleCountTags.h"
#include "createInvoices.h"
#include "createItemSitesByClassCode.h"
#include "createLotSerial.h"
#include "createPlannedOrdersByItem.h"
#include "createPlannedOrdersByPlannerCode.h"
#include "createRecurringInvoices.h"
#include "createRecurringItems.h"
#include "creditCard.h"
#include "creditMemoEditList.h"
#include "creditMemo.h"
#include "creditMemoItem.h"
#include "crmaccount.h"
#include "crmaccounts.h"
#include "currencies.h"
#include "currencyConversion.h"
#include "currencyConversions.h"
#include "currency.h"
#include "currencySelect.h"
#include "customCommandArgument.h"
#include "customCommand.h"
#include "customCommands.h"
#include "customerFormAssignment.h"
#include "customerFormAssignments.h"
#include "customerGroup.h"
#include "customerGroups.h"
#include "customer.h"
#include "customers.h"
#include "customerType.h"
#include "customerTypeList.h"
#include "customerTypes.h"
#include "databaseInformation.h"
#include "deletePlannedOrder.h"
#include "deletePlannedOrdersByPlannerCode.h"
#include "department.h"
#include "departments.h"
#include "distributeInventory.h"
#include "distributeToLocation.h"
#include "dspAllocations.h"
#include "dspAPApplications.h"
#include "dspAPOpenItemsByVendor.h"
#include "dspARApplications.h"
#include "dspAROpenItems.h"
#include "dspBacklog.h"
#include "dspBankrecHistory.h"
#include "dspBillingSelections.h"
#include "dspBookings.h"
#include "dspBriefEarnedCommissions.h"
#include "dspBriefSalesHistory.h"
#include "dspCapacityUOMsByClassCode.h"
#include "dspCapacityUOMsByProductCategory.h"
#include "dspCashReceipts.h"
#include "dspCheckRegister.h"
#include "dspCostedIndentedBOM.h"
#include "dspCostedSingleLevelBOM.h"
#include "dspCostedSummarizedBOM.h"
#include "dspCountSlipEditList.h"
#include "dspCountSlipsByWarehouse.h"
#include "dspCountTagEditList.h"
#include "dspCountTagsByClassCode.h"
#include "dspCountTagsByItem.h"
#include "dspCountTagsByWarehouse.h"
#include "dspCustomerARHistory.h"
#include "dspDepositsRegister.h"
#include "dspDetailedInventoryHistoryByLocation.h"
#include "dspDetailedInventoryHistoryByLotSerial.h"
#include "dspEarnedCommissions.h"
#include "dspExpediteExceptionsByPlannerCode.h"
#include "dspExpiredInventoryByClassCode.h"
#include "dspFinancialReport.h"
#include "dspFreightPricesByCustomer.h"
#include "dspFreightPricesByCustomerType.h"
#include "dspFrozenItemSites.h"
#include "dspGLSeries.h"
#include "dspGLTransactions.h"
#include "dspIndentedBOM.h"
#include "dspIndentedWhereUsed.h"
#include "dspInvalidBillsOfMaterials.h"
#include "dspInventoryAvailabilityByCustomerType.h"
#include "dspInventoryAvailabilityByWorkOrder.h"
#include "dspInventoryHistory.h"
#include "dspInventoryLocator.h"
#include "dspInvoiceInformation.h"
#include "dspInvoiceRegister.h"
#include "dspItemCostDetail.h"
#include "dspItemCostHistory.h"
#include "dspItemCostsByClassCode.h"
#include "dspItemCostSummary.h"
#include "dspItemSources.h"
#include "dspItemSourcePrices.h"
#include "dspItemsWithoutItemSources.h"
#include "dspJobCosting.h"
#include "dspMaterialUsageVarianceByBOMItem.h"
#include "dspMaterialUsageVarianceByComponentItem.h"
#include "dspMaterialUsageVarianceByItem.h"
#include "dspMaterialUsageVarianceByWarehouse.h"
#include "dspMaterialUsageVarianceByWorkOrder.h"
#include "dspMRPDetail.h"
#include "dspOrderActivityByProject.h"
#include "dspOrders.h"
#include "dspPartiallyShippedOrders.h"
#include "dspPendingAvailability.h"
#include "dspPendingBOMChanges.h"
#include "dspPlannedOrders.h"
#include "dspPoDeliveryDateVariancesByItem.h"
#include "dspPoDeliveryDateVariancesByVendor.h"
#include "dspPoHistory.h"
#include "dspPoItemReceivingsByDate.h"
#include "dspPoItemReceivingsByItem.h"
#include "dspPoItemReceivingsByVendor.h"
#include "dspPoItemsByDate.h"
#include "dspPoItemsByItem.h"
#include "dspPoItemsByVendor.h"
#include "dspPoPriceVariancesByItem.h"
#include "dspPoPriceVariancesByVendor.h"
#include "dspPoReturnsByVendor.h"
#include "dspPOsByDate.h"
#include "dspPOsByVendor.h"
#include "dspPricesByCustomer.h"
#include "dspPricesByCustomerType.h"
#include "dspPricesByItem.h"
#include "dspPurchaseReqsByItem.h"
#include "dspPurchaseReqsByPlannerCode.h"
#include "dspQOH.h"
#include "dspQOHByLocation.h"
#include "dspQuotesByCustomer.h"
#include "dspQuotesByItem.h"
#include "dspReorderExceptionsByPlannerCode.h"
#include "dspReservations.h"
#include "dspRunningAvailability.h"
#include "dspSalesHistory.h"
#include "dspSalesOrders.h"
#include "dspSalesOrdersByItem.h"
#include "dspSalesOrderStatus.h"
#include "dspShipmentsByDate.h"
#include "dspShipmentsBySalesOrder.h"
#include "dspShipmentsByShipment.h"
#include "dspSingleLevelBOM.h"
#include "dspSingleLevelWhereUsed.h"
#include "dspSlowMovingInventoryByClassCode.h"
#include "dspStandardJournalHistory.h"
#include "dspSubstituteAvailabilityByItem.h"
#include "dspSummarizedBacklogByWarehouse.h"
#include "dspSummarizedBankrecHistory.h"
#include "dspSummarizedBOM.h"
#include "dspSummarizedGLTransactions.h"
#include "dspSummarizedSales.h"
#include "dspTax1099.h"
#include "dspTaxHistory.h"
#include "dspTimePhasedAvailability.h"
#include "dspTimePhasedBookings.h"
#include "dspTimePhasedOpenAPItems.h"
#include "dspTimePhasedOpenARItems.h"
#include "dspTimePhasedSales.h"
#include "dspTimePhasedUsageStatisticsByItem.h"
#include "dspTrialBalances.h"
#include "dspUnbalancedQOHByClassCode.h"
#include "dspUndefinedManufacturedItems.h"
#include "dspUninvoicedReceivings.h"
#include "dspUnusedPurchasedItems.h"
#include "dspUsageStatistics.h"
#include "dspUserPrivileges.h"
#include "dspValidLocationsByItem.h"
#include "dspVendorAPHistory.h"
#include "dspVoucherRegister.h"
#include "dspWoHistoryByClassCode.h"
#include "dspWoHistoryByItem.h"
#include "dspWoHistoryByNumber.h"
#include "dspWoMaterialsByItem.h"
#include "dspWoMaterialsByWorkOrder.h"
#include "dspWoSchedule.h"
#include "duplicateAccountNumbers.h"
#include "editOwners.h"
#include "empGroup.h"
#include "empGroups.h"
#include "employee.h"
#include "employees.h"
#include "enterMiscCount.h"
#include "enterPoitemReceipt.h"
#include "enterPoitemReturn.h"
#include "enterPoReceipt.h"
#include "enterPoReturn.h"
#include "errorLog.h"
#include "eventManager.h"
#include "expenseCategories.h"
#include "expenseCategory.h"
#include "expenseTrans.h"
#include "explodeWo.h"
#include "exportData.h"
#include "externalCCTransaction.h"
#include "externalShipping.h"
#include "externalShippingList.h"
#include "failedPostList.h"
#include "financialLayoutColumns.h"
#include "financialLayoutGroup.h"
#include "financialLayout.h"
#include "financialLayoutItem.h"
#include "financialLayouts.h"
#include "financialLayoutSpecial.h"
#include "firmPlannedOrder.h"
#include "firmPlannedOrdersByPlannerCode.h"
#include "fixACL.h"
#include "fixSerial.h"
#include "form.h"
#include "forms.h"
#include "forwardUpdateAccounts.h"
#include "freightBreakdown.h"
#include "freightClasses.h"
#include "freightClass.h"
#include "getGLDistDate.h"
#include "getLotInfo.h"
#include "glSeries.h"
#include "glSeriesItem.h"
#include "glTransactionDetail.h"
#include "glTransaction.h"
#include "group.h"
#include "groups.h"
#include "honorific.h"
#include "honorifics.h"
#include "hotkey.h"
#include "hotkeys.h"
#include "idleShutdown.h"
#include "image.h"
#include "imageList.h"
#include "images.h"
#include "implodeWo.h"
#include "importData.h"
#include "incidentCategories.h"
#include "incidentCategory.h"
#include "incident.h"
#include "incidentPriorities.h"
#include "incidentPriority.h"
#include "incidentResolution.h"
#include "incidentResolutions.h"
#include "incidentSeverities.h"
#include "incidentSeverity.h"
#include "incidentWorkbench.h"
#include "invoice.h"
#include "invoiceItem.h"
#include "invoiceList.h"
#include "issueLineToShipping.h"
#include "issueToShipping.h"
#include "issueWoMaterialBatch.h"
#include "issueWoMaterialItem.h"
#include "itemAlias.h"
#include "itemAvailabilityWorkbench.h"
#include "itemCost.h"
#include "itemGroup.h"
#include "itemGroups.h"
#include "item.h"
#include "itemImages.h"
#include "itemListPrice.h"
#include "itemPricingSchedule.h"
#include "itemPricingScheduleItem.h"
#include "itemPricingSchedules.h"
#include "items.h"
#include "itemSite.h"
#include "itemSites.h"
#include "itemSource.h"
#include "itemSourceList.h"
#include "itemSourcePrice.h"
#include "itemSourceSearch.h"
#include "itemSubstitute.h"
#include "itemtax.h"
#include "itemUOM.h"
#include "labelForm.h"
#include "labelForms.h"
#include "ledgerControl.h"
#include "listRecurringInvoices.h"
#include "locales.h"
#include "location.h"
#include "locations.h"
#include "lotSerial.h"
#include "lotSerialSequences.h"
#include "lotSerialRegistration.h"
#include "maintainBudget.h"
#include "maintainItemCosts.h"
#include "maintainShipping.h"
#include "massExpireComponent.h"
#include "massReplaceComponent.h"
#include "materialReceiptTrans.h"
#include "metasqls.h"
#include "miscCheck.h"
#include "miscVoucher.h"
#include "openReturnAuthorizations.h"
#include "openSalesOrders.h"
#include "openVouchers.h"
#include "opportunity.h"
#include "opportunityList.h"
#include "opportunitySource.h"
#include "opportunitySources.h"
#include "opportunityStage.h"
#include "opportunityStages.h"
#include "opportunityType.h"
#include "opportunityTypes.h"
#include "package.h"
#include "packages.h"
#include "packingListBatch.h"
#include "plannedOrder.h"
#include "plannerCode.h"
#include "plannerCodes.h"
#include "poLiabilityDistrib.h"
#include "postCashReceipts.h"
#include "postCheck.h"
#include "postChecks.h"
#include "postCostsByClassCode.h"
#include "postCostsByItem.h"
#include "postCountSlips.h"
#include "postCountTags.h"
#include "postCreditMemos.h"
#include "postInvoices.h"
#include "postMiscProduction.h"
#include "postPoReturnCreditMemo.h"
#include "postProduction.h"
#include "postPurchaseOrder.h"
#include "postPurchaseOrdersByAgent.h"
#include "postStandardJournalGroup.h"
#include "postStandardJournal.h"
#include "postVouchers.h"
#include "poType.h"
#include "poTypes.h"
#include "prepareCheckRun.h"
#include "priceList.h"
#include "pricingScheduleAssignment.h"
#include "pricingScheduleAssignments.h"
#include "printCheck.h"
#include "printChecks.h"
#include "printChecksReview.h"
#include "printCreditMemo.h"
#include "printCreditMemos.h"
#include "printInvoice.h"
#include "printInvoices.h"
#include "printItemLabelsByClassCode.h"
#include "printLabelsByInvoice.h"
#include "printLabelsByOrder.h"
#include "printLabelsBySo.h"
#include "printLabelsByTo.h"
#include "printMulticopyDocument.h"
#include "printOptions.h"
#include "printPackingListBatchByShipvia.h"
#include "printPackingList.h"
#include "printPoForm.h"
#include "printToForm.h"
#include "printPurchaseOrder.h"
#include "printPurchaseOrdersByAgent.h"
#include "printRaForm.h"
#include "printShippingForm.h"
#include "printShippingForms.h"
#include "printSoForm.h"
#include "printStatementByCustomer.h"
#include "printStatementsByCustomerType.h"
#include "printVendorForm.h"
#include "printWoForm.h"
#include "printWoPickList.h"
#include "printWoTraveler.h"
#include "productCategories.h"
#include "productCategory.h"
#include "profitCenter.h"
#include "profitCenters.h"
#include "project.h"
#include "projects.h"
#include "projectTypes.h"
#include "prospect.h"
#include "prospects.h"
#include "purchaseOrder.h"
#include "purchaseOrderItem.h"
#include "purchaseRequest.h"
#include "purgeClosedWorkOrders.h"
#include "purgeCreditMemos.h"
#include "purgeInvoices.h"
#include "purgePostedCounts.h"
#include "purgePostedCountSlips.h"
#include "quickRelocateLot.h"
#include "quotes.h"
#include "reasonCode.h"
#include "reasonCodes.h"
#include "reassignClassCodeByClassCode.h"
#include "reassignCustomerTypeByCustomerType.h"
#include "reassignLotSerial.h"
#include "reassignProductCategoryByProductCategory.h"
#include "recallOrders.h"
#include "reconcileBankaccount.h"
#include "registrationKey.h"
#include "rejectCode.h"
#include "rejectCodes.h"
#include "relativeCalendarItem.h"
#include "releasePlannedOrdersByPlannerCode.h"
#include "releaseTransferOrdersByAgent.h"
#include "releaseWorkOrdersByPlannerCode.h"
#include "relocateInventory.h"
#include "reports.h"
#include "reprintCreditMemos.h"
#include "reprintInvoices.h"
#include "reprintMulticopyDocument.h"
#include "reprioritizeWo.h"
#include "reschedulePoitem.h"
#include "rescheduleWo.h"
#include "reserveSalesOrderItem.h"
#include "resetQOHBalances.h"
#include "returnAuthCheck.h"
#include "returnAuthItemLotSerial.h"
#include "returnAuthorization.h"
#include "returnAuthorizationItem.h"
#include "returnAuthorizationWorkbench.h"
#include "returnWoMaterialBatch.h"
#include "returnWoMaterialItem.h"
#include "reverseGLSeries.h"
#include "sale.h"
#include "salesAccount.h"
#include "salesAccounts.h"
#include "salesCategories.h"
#include "salesCategory.h"
#include "sales.h"
#include "salesHistoryInformation.h"
#include "salesOrder.h"
#include "salesOrderInformation.h"
#include "salesOrderItem.h"
#include "salesOrderSimple.h"
#include "salesRep.h"
#include "salesReps.h"
#include "saleType.h"
#include "saleTypes.h"
#include "scrapTrans.h"
#include "scrapWoMaterialFromWIP.h"
#include "scriptEditor.h"
#include "scripts.h"
#include "searchForEmp.h"
#include "selectBankAccount.h"
#include "selectBillingQty.h"
#include "selectedPayments.h"
#include "selectOrderForBilling.h"
#include "selectPayment.h"
#include "selectPayments.h"
#include "selectShippedOrders.h"
#include "setup.h"
#include "shipOrder.h"
#include "shippingChargeType.h"
#include "shippingChargeTypes.h"
#include "shippingForm.h"
#include "shippingForms.h"
#include "shippingInformation.h"
#include "shippingZone.h"
#include "shippingZones.h"
#include "shipTo.h"
#include "shipVia.h"
#include "shipVias.h"
#include "siteType.h"
#include "siteTypes.h"
#include "splitReceipt.h"
#include "standardJournalGroup.h"
#include "standardJournalGroupItem.h"
#include "standardJournalGroups.h"
#include "standardJournal.h"
#include "standardJournalItem.h"
#include "standardJournals.h"
#include "states.h"
#include "subAccntType.h"
#include "subAccntTypes.h"
#include "subaccount.h"
#include "subaccounts.h"
#include "submitAction.h"
#include "submitReport.h"
#include "substituteList.h"
#include "summarizeInvTransByClassCode.h"
#include "syncCompanies.h"
#include "sysLocale.h"
#include "systemMessage.h"
#include "task.h"
#include "taxAuthorities.h"
#include "taxAuthority.h"
#include "taxBreakdown.h"
#include "taxclasses.h"
#include "taxClass.h"
#include "taxCode.h"
#include "taxCodeRate.h"
#include "taxCodes.h"
#include "taxDetail.h"
#include "taxRegistration.h"
#include "taxRegistrations.h"
#include "taxType.h"
#include "taxTypes.h"
#include "taxZone.h"
#include "taxZones.h"
#include "termses.h"
#include "terms.h"
#include "thawItemSitesByClassCode.h"
#include "todoItem.h"
#include "todoListCalendar.h"
#include "todoList.h"
#include "toggleBankrecCleared.h"
#include "transactionInformation.h"
#include "transferOrder.h"
#include "transferOrderItem.h"
#include "transferOrders.h"
#include "transferTrans.h"
#include "transformTrans.h"
#include "uiform.h"
#include "uiforms.h"
#include "unappliedAPCreditMemos.h"
#include "unappliedARCreditMemos.h"
#include "uninvoicedShipments.h"
#include "unpostedCreditMemos.h"
#include "unpostedGlSeries.h"
#include "unpostedGLTransactions.h"
#include "unpostedInvoices.h"
#include "unpostedPoReceipts.h"
#include "unpostedPurchaseOrders.h"
#include "uomConv.h"
#include "uom.h"
#include "uoms.h"
#include "updateABCClass.h"
#include "updateActualCostsByClassCode.h"
#include "updateActualCostsByItem.h"
#include "updateCreditStatusByCustomer.h"
#include "updateCycleCountFrequency.h"
#include "updateItemSiteLeadTimes.h"
#include "updateLateCustCreditStatus.h"
#include "updateListPricesByProductCategory.h"
#include "updateOUTLevelByItem.h"
#include "updateOUTLevelsByClassCode.h"
#include "updateOUTLevels.h"
#include "updatePrices.h"
#include "updateReorderLevels.h"
#include "userCostingElement.h"
#include "user.h"
#include "userList.h"
#include "userPreferences.h"
#include "users.h"
#include "vendorAddress.h"
#include "vendorAddressList.h"
#include "vendor.h"
#include "vendors.h"
#include "vendorPriceList.h"
#include "vendorType.h"
#include "vendorTypes.h"
#include "viewCheckRun.h"
#include "voidChecks.h"
#include "voucher.h"
#include "voucherItemDistrib.h"
#include "voucherItem.h"
#include "voucherMiscDistrib.h"
#include "warehouse.h"
#include "warehouses.h"
#include "warehouseZone.h"
#include "woMaterialItem.h"
#include "workOrder.h"
#include "workOrderMaterials.h"
#include "xdateinputdialog.h"
#include "xsltMap.h"
#include "zeroUncountedCountTagsByWarehouse.h"
