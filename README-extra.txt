Qt and Android.

ZBridgeE:

ItemisCEATE (Yakindu)generated files:
sctypes.h: line 33 outcomment, #define null 0


Installation of Qt:
Select Windows and Android.
after installation of Qt, install MSVC 2019.

QtCreator > Tools > Qt Maintenance Tool > Start Maintenance Tool
inklude MSVC2019, QtWebengine, QtPositioning, QtWebchannel, QtWebview (2 places).
ZBridgeE Help uses QtWebview, which cannot be used with the mingw compilers.

QtCreator > Edit > Preferences
Android tab: update/install JDK, Android SDK, OpenSSL
Devices tab: create relevant AVD's (install emulator images etc.)

Configure hardware acceleration for the Android Emulator. Normally hardware is used
for the emulator, but if the graphics drivers are not compatible with the emulator
software software acceleration must be used:
Choose a hypervisor on windows (WHPX)
1. From the Windows Desktop, right click the Windows Icon and select "Apps and
features"
2. Under related settings, click "Progress and Features".
3. Click "Turns Windows Features on or off"
4. Select "Windows Hypervisor Platforms".
5. Click Ok.

Android hardware (phone, tablet etc.).
Enable developer mode
	Setup > About the Phone > Software Information:
	tap build number a number of times and enable Developer Mode.
	Setup > Developer Settings:
	1. Select do not lock screen during charging.
	2. Select USB fejlretning.
Install USB driver on development machine:
	Right click on the file AndroidSDK>extras>google>usb_driver android_winusb.inf
	and install the USB driver (the Windows standard USB driver cannot be used).
	
Connect your Android device to the development machine wit a USB cable.
Test if the connection is working with AndroidSDK>platform-tools adb.exe:
	adb kill-server
	adb start-server
	adb devices
and the Android device should be shown.