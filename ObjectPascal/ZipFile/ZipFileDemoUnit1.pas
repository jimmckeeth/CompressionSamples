unit ZipFileDemoUnit1;

interface

uses
  System.SysUtils, System.Types, System.UITypes, System.Classes, System.Variants,
  FMX.Types, FMX.Controls, FMX.Forms, FMX.Graphics, FMX.Dialogs,
  FMX.Controls.Presentation, FMX.StdCtrls;

type
  TForm30 = class(TForm)
    Button1: TButton;
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form30: TForm30;

implementation

{$R *.fmx}

uses
  System.IOUtils, System.Zip;

procedure TForm30.Button1Click(Sender: TObject);
var
  zip: TZipFile;
begin
  zip := TZipFile.Create;
  try

    zip.Open();
    zip.Close;
  finally
    zip.Free;

  end;
end;

end.
