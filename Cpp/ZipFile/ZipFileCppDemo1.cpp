//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ZipFileCppDemo1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm29 *Form29;
//---------------------------------------------------------------------------
__fastcall TForm29::TForm29(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm29::Button1Click(TObject *Sender)
{
	String FileName = "demo.zip";
	if (TFile::Exists(FileName)) {
		TFile::Delete(FileName);
	}

	TStringDynArray list;

	list = TDirectory::GetFiles("..\\..");

	std::auto_ptr<TZipFile> zip(new TZipFile());
	zip->Open(FileName, zmWrite);

	for (int i = 0; i < list.Length; i++) {
	   String individual = System::Ioutils::TPath::GetFileName(list[i]);
	   zip->Add(list[i], individual);

	   double ratio = zip->FileInfo[i].CompressedSize
	   	/ (double)zip->FileInfo[i].UncompressedSize;

	   ListBox1->Items->Add(Format("%f %s", ARRAYOFCONST((ratio, individual))));
	}

	zip->Close();
}
//---------------------------------------------------------------------------
