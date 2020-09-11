
//	Имя компьютера, имя пользователя;
//	Пути к системным каталогам Windows;
//	Версия операционной системы;
//	Системные метрики(не менее 2 метрик);
//	Системные параметры(не менее 2 параметров);
//	Системные цвета(определить цвет для некоторых символьных констант и изменить его на любой другой);
//	Функции для работы со временем;
//	Дополнительные API - функции:
//GetClipCursor, GetKeyboardType, GetUserDefaultLCID, ShowCursor


#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <locale>
#define cout wcout
#define OSVERSIONINFO OSVERSIONINFOEX
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	cout.imbue(locale("rus_rus.1251"));
	WCHAR str[4096];
	DWORD sz = 4096;

	GetUserName(str, &sz);
	cout << "Имя пользователя:  " << str << endl;

	GetComputerName(str,&sz);
	cout << "Имя компьютера:  " << str << endl;

	GetSystemDirectory(str, 4096);
	cout << "Путь к системной папке:  " << str<< endl;

	GetWindowsDirectory(str, 4096);
	cout << "Пути к папке windows:  " << str<< endl;

	GetTempPath(4096, str);
	cout << "Путь к временной папке:  " << str<< endl;

	OSVERSIONINFO osversion;
	memset(&osversion, 0, sizeof(OSVERSIONINFO));
	osversion.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	//GetVersionEX(&osversion);


	cout << "Версия системы (Основной номер. дополнительный. сборка)" << osversion.dwMajorVersion << "." << osversion.dwMinorVersion << "." << osversion.dwBuildNumber << endl
		<< "Размер структуры OSVERSIONINFO:  " << osversion.dwOSVersionInfoSize<<endl
		<< "Платформа операционной системы:  " << osversion.dwPlatformId<<endl
		<< "Последний установленный служебный пакет:  " << osversion.szCSDVersion<<endl
		<< endl << "Системные метрики:" << endl 
		<< "Разрешение экрана:  " << GetSystemMetrics(0) 
		<< "x" << GetSystemMetrics(1) << endl
		<< "Есть ли колесо прокрутки у мышки?  ";
		GetSystemMetrics(75) ? cout << "Да" << endl : cout << "Нет" << endl;
		cout << "Количество клавиш у мышки: " << GetSystemMetrics(43) << endl
			<< "клавиши мыши можно поменять местами?";
		GetSystemMetrics(23) ? cout << "Да" << endl : cout << "Нет" << endl;
	unsigned int param;
	SystemParametersInfo(SPI_GETACCESSTIMEOUT, 0, &param, 0);
	cout << endl<< "Системные параметры:\nПараметр SPI_GETACCESSTIMEOUT:  " << param<< endl;// Временные интервалы
	SystemParametersInfo(SPI_GETANIMATION, 0, &param, 0);
	cout << "Параметр SPI_GETANIMATION:  " << param<< endl; //Данные об анимации
	SystemParametersInfo(SPI_GETBEEP, 0, &param, 0);
	cout << "Признак разрешения звуковых сигналов:  " << param<< endl;
	SystemParametersInfo(SPI_GETICONMETRICS, 0, &param, 0);
	cout << "Признак, дающий информацию о характеристиках  иконок:  " << param<< endl;
	int n[] = { COLOR_3DDKSHADOW, COLOR_3DDKSHADOW };
	COLORREF color = GetSysColor(n[0]);//Dark shadow for three-dimensional display elements.
	COLORREF color2 = GetSysColor(n[1]);//Desktop.
	unsigned long p[] = { color, color2 };
	COLORREF newcolor[] = { RGB(150, 75, 0), RGB(0, 0, 255) };//Коричневый//Синий
	SetSysColors(2, n, newcolor);
	cout << "Изменён цвет тени для элементов.\nНажмите любую клавишу для возвращение в исходное состояние.";
	_getch();
	SetSysColors(2, n, p);
	SYSTEMTIME var1, var2;
	GetLocalTime(&var1);
	GetSystemTime(&var2);
	cout << "\n\nИнформаци о времени:\nЛокальное время:  дата  " << var1.wDay << "." << var1.wMonth << L"." << var1.wYear << " время  " << var1.wHour << ":" << var1.wMinute
	<< "\nСистемное время:  "
	<< "дата  " << var2.wDay << "." << var2.wMonth << "." << var2.wYear << " время  " << var2.wHour << ":" << var2.wMinute<<endl;

	cout << "\n\n Индивидуальное задание\n";
	RECT mem;
	GetClipCursor(&mem);
	cout << "\n1.GetClipCursor = " <<mem.left<<"."<< mem.bottom<<"."<<mem.right<<"."<<mem.top;
	wcout<<"\n1.Курсор заблокирован в пределах {400,400,600,600}\n";
	mem={400,400,600,600};
	ClipCursor(&mem);
	cout << "\n1.GetClipCursor. Новые значения = " << mem.left << "." << mem.bottom << "." << mem.right << "." << mem.top;
	_getch();
	cout << "\n2.GetKeyboardLayoutType = " << str
	<< "\n3.GetUserDefaultLCID (Идентификатор определяемого пользователем языка операционной системы)= " << GetUserDefaultLCID()<<endl;
	cout << "\n4.Параметры курсора= " <<ShowCursor(1)<<endl;
	system("PAUSE");
	return 0;
}
