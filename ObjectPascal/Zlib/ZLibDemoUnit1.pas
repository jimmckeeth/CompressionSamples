unit ZLibDemoUnit1;

interface

uses
  System.SysUtils, System.Types, System.UITypes, System.Classes, System.Variants,
  FMX.Types, FMX.Controls, FMX.Forms, FMX.Graphics, FMX.Dialogs,

  System.ZLib,

  FMX.ScrollBox,
  FMX.Memo, FMX.StdCtrls, FMX.Edit, FMX.Controls.Presentation, FMX.Layouts,
  FMX.TabControl, FMX.ListBox;

type
  TForm27 = class(TForm)
    Memo1: TMemo;
    TabControl1: TTabControl;
    TabItem1: TTabItem;
    Layout1: TLayout;
    btnCompress: TButton;
    TabItem2: TTabItem;
    ListBox1: TListBox;
    TabItem3: TTabItem;
    Memo2: TMemo;
    procedure btnCompressClick(Sender: TObject);
  private
    procedure TestCompression(compressionLevel: TCompressionLevel);
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form27: TForm27;

implementation

{$R *.fmx}

uses
  System.IOUtils, System.Hash, System.TypInfo;

procedure TForm27.TestCompression(compressionLevel: TZCompressionLevel);
var
  DeHash: string;
  UnHash: string;
  LUncompressed: TStringStream;
  LCompressed: TMemoryStream;
begin
  LUncompressed := nil;
  LCompressed := nil;
  try
    //--------------
    // Compression
    //--------------
    // Holds uncompressed data
    LUncompressed := TStringStream.Create;
    // Holds compressed data
    LCompressed := TMemoryStream.Create;
    // Load the uncompressed data
    LUncompressed.WriteString(Memo1.Text);
    LUncompressed.Position := 0;
    // Perform compression
    ZCompressStream(LUncompressed, LCompressed, compressionLevel);
    //---------------
    // Decompression (Could also use ZDecompressStream procedure)
    //---------------
    // Read from the start of the steam
    LCompressed.Position := 0;
    // reusing the stream
    LUncompressed.Clear;
    // Decompress
    ZDecompressStream(LCompressed, LUncompressed);
    Memo2.Text := LUncompressed.DataString;
    //--------------
    // Log the data
    //--------------
    ListBox1.Items.Add('--------');
    ListBox1.Items.Add('Using ' + GetEnumName(
      System.TypeInfo(TCompressionLevel), ord(compressionLevel)));
    ListBox1.Items.Add(Format('Sizes: %d / %d / %d',
       [Memo1.Text.Length, LCompressed.Size, Memo2.Text.Length]));
    ListBox1.Items.Add(Format('Ratio: %f', [LCompressed.Size / Memo1.Text.Length]));
    UnHash := THashBobJenkins.GetHashString(Memo1.Text);
    DeHash := THashBobJenkins.GetHashString(Memo2.Text);
    // Test the hashes
    if UnHash = DeHash then
      ListBox1.Items.Add(Format('Hashes: %s / %s Match', [UnHash, DeHash]))
    else
      ListBox1.Items.Add(Format('Hashes: %s / %s Fail', [UnHash, DeHash]));
    //-----------
    // Clean-up
    //-----------
    finally
      LUncompressed.Free;
      LCompressed.Free;
    end;
end;

procedure TForm27.btnCompressClick(Sender: TObject);
begin
  ListBox1.Clear;
  TabControl1.ActiveTab := TabItem2;
  TestCompression(zcNone);
  TestCompression(zcFastest);
  TestCompression(zcDefault);
  TestCompression(zcMax);
end;

end.
