[Setup]
OutputBaseFilename=Blitz3DSetup1110
OutputDir=.\

AppName=Blitz3D
AppVerName=Blitz3D 1.110
AppPublisher=Blitz Research Ltd
AppPublisherURL=http://www.blitzbasic.com
DefaultDirName={sd}\Blitz3D
DefaultGroupName=Blitz3D

AllowRootDirectory=yes
DisableStartupPrompt=yes

[Icons]
Name: "{group}\Blitz3D"; Filename: "{app}\Blitz3D.exe"; WorkingDir: "{app}";
Name: "{group}\Uninstall Blitz3D"; Filename: "{uninstallexe}";

[Files]
Source: ".\_release\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs

[Run]
Filename: "{app}\Blitz3D.exe"; Description: "Launch Blitz3D"; Flags: postinstall nowait skipifsilent
