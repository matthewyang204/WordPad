# WordPad
<img width="5120" height="2880" alt="Screenshot 2025-10-08 194535" src="https://github.com/user-attachments/assets/feb965fa-83ba-4d7f-8ab1-e4214a97bb45" />
This is continued development of WordPad. It is based off of the better, older version of WordPad bundled with Windows XP and prior versions. It has three themes. I found the source code hiding at the bottom of one of Microsoft's sample archives. For the reason I developed this, the backstory is that I used WordPad on Windows XP on my childhood computer. It was simple and got all word procesing done fast, taking less than 3 seconds to launch. And fast forward to today, as a software developer, I got very angry that Microsoft got rid of it in Windows 11 24H2. So I was determined to get my hands on the source legally somehow, and here it is. I found the XP version of it (which I like better than the modern Aero version that shipped with Windows 7+), finally, at the bottom of Microsoft's very own archives, and am in the process of modernizing it. Enjoy using this dream project of mine!

# Requirements
- Windows XP or later (please note that if you are using WinXP, you will need to use [exeosver](https://github.com/camthesaxman/exeosver) to patch the main executable after installation)
- 512 MB or more of RAM
- Pentium III or better

Additionally, for development:
- Windows 7 or later
- Intel Core Duo or better
- 4 GB or more of RAM
- Visual Studio 2019
- C++ Desktop Development workflow installed in VS
- C++ MFC & ATL Libraries installed in VS
- Inno Setup 6.43 or later

# Installation
Just run the installer.

# Development
For testing, you will need to build the project with the `Debug | Win32` configuration. After compiling, open up the Debug folder or start the application right in Visual Studio. You can build installers by compiling for `Release | Win32` and then opening up Inno Setup 6.43 or later and hitting either Ctrl+F9 or `Build > Compile` in the bar at the top of the window.

## This Is A Fork
Please note that this project is a fork. It is continued development on WordPad based off the edition of WordPad packaged with Windows XP and earlier found hiding in the Microsoft VC++ Samples repo. You can check out the [VCSamples](https://github.com/microsoft/VCSamples) repo; the src was found in the [WordPad](https://github.com/microsoft/VCSamples/tree/master/VC2010Samples/MFC/Visual%20C%2B%2B%202008%20Feature%20Pack/WordPad) section.

# License
This project is licensed under the MIT license to Microsoft and Matthew Yang (杨佳明). This applies to all versions future or past. See the [license file](LICENSE) for more details.
