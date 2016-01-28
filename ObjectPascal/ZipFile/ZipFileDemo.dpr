program ZipFileDemo;

uses
  System.StartUpCopy,
  FMX.Forms,
  ZipFileDemoUnit1 in 'ZipFileDemoUnit1.pas' {Form30};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm30, Form30);
  Application.Run;
end.
