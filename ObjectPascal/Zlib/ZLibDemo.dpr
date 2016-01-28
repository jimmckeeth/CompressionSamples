program ZLibDemo;

uses
  System.StartUpCopy,
  FMX.Forms,
  ZLibDemoUnit1 in 'ZLibDemoUnit1.pas' {Form27};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm27, Form27);
  Application.Run;
end.
