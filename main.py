import MainFrame
import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import (QWidget, QLCDNumber, QSlider, QVBoxLayout, QApplication, QMainWindow)

if __name__ == '__main__':
	app = QApplication(sys.argv)
	mainWindow = QMainWindow()
	ui = MainFrame.Ui_MainWindow()
	ui.setupUi(mainWindow)
	mainWindow.show()
	sys.exit(app.exec_())