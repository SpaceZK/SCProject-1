# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'res/MainFrame.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 600)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.leTotalLength = QtWidgets.QLineEdit(self.centralwidget)
        self.leTotalLength.setGeometry(QtCore.QRect(30, 50, 113, 20))
        self.leTotalLength.setObjectName("leTotalLength")
        self.leCuttingLength = QtWidgets.QLineEdit(self.centralwidget)
        self.leCuttingLength.setGeometry(QtCore.QRect(30, 120, 113, 20))
        self.leCuttingLength.setObjectName("leCuttingLength")
        self.btnAddCuttingLength = QtWidgets.QPushButton(self.centralwidget)
        self.btnAddCuttingLength.setGeometry(QtCore.QRect(160, 120, 91, 23))
        self.btnAddCuttingLength.setObjectName("btnAddCuttingLength")
        self.btnSetTotalLength = QtWidgets.QPushButton(self.centralwidget)
        self.btnSetTotalLength.setGeometry(QtCore.QRect(160, 50, 91, 23))
        self.btnSetTotalLength.setObjectName("btnSetTotalLength")
        self.btnGenerateResult = QtWidgets.QPushButton(self.centralwidget)
        self.btnGenerateResult.setGeometry(QtCore.QRect(334, 90, 91, 23))
        self.btnGenerateResult.setObjectName("btnGenerateResult")
        self.btnSelectAll = QtWidgets.QPushButton(self.centralwidget)
        self.btnSelectAll.setGeometry(QtCore.QRect(550, 30, 75, 23))
        self.btnSelectAll.setObjectName("btnSelectAll")
        self.btnSelectInvert = QtWidgets.QPushButton(self.centralwidget)
        self.btnSelectInvert.setGeometry(QtCore.QRect(650, 30, 75, 23))
        self.btnSelectInvert.setObjectName("btnSelectInvert")
        self.btnDeleteSelections = QtWidgets.QPushButton(self.centralwidget)
        self.btnDeleteSelections.setGeometry(QtCore.QRect(644, 420, 91, 23))
        self.btnDeleteSelections.setObjectName("btnDeleteSelections")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 23))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.btnAddCuttingLength.setText(_translate("MainWindow", "添加切割长度"))
        self.btnSetTotalLength.setText(_translate("MainWindow", "修改总长度"))
        self.btnGenerateResult.setText(_translate("MainWindow", "生成切割方法"))
        self.btnSelectAll.setText(_translate("MainWindow", "全选"))
        self.btnSelectInvert.setText(_translate("MainWindow", "反选"))
        self.btnDeleteSelections.setText(_translate("MainWindow", "删除选中项"))

