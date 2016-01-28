program RestZlibDemo;

uses
  System.StartUpCopy,
  FMX.Forms,
  RestZlibDemoUnit1 in 'RestZlibDemoUnit1.pas' {Form27},
  RestDecompress in 'RestDecompress.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm27, Form27);
  Application.Run;
end.
