//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "zlibCppDemo1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TForm7::TestCompress(TZCompressionLevel ACompressionLevel)
{
	// Stream hodling the source data
	std::auto_ptr<TStringStream> LUncompressed(new TStringStream());
	LUncompressed->WriteString(Memo1->Text);
	LUncompressed->Position = 0;
	// Stream to hold the compressed data
	std::auto_ptr<TMemoryStream> LCompressed(new TMemoryStream());
	// Performming the compression
	ZCompressStream(LUncompressed.get(), LCompressed.get(), ACompressionLevel);
	//--------------
	// Decompression
	//--------------
	LCompressed->Position = 0;
	LUncompressed->Clear();
	ZDecompressStream(LCompressed.get(), LUncompressed.get());
	Memo2->Text = LUncompressed->DataString;

	//---------
	// Logging
	//---------
	ListBox1->Items->Add(Format("Sizes: %d / %d / %d",
	ARRAYOFCONST((Memo1->Text.Length(), LCompressed->Size, Memo2->Text.Length()))));
	ListBox1->Items->Add(Format("Ratio: %f",
	ARRAYOFCONST((LCompressed->Size / (double)Memo1->Text.Length()))));
	String UnHash = THashBobJenkins::GetHashString(Memo1->Text);
	String DeHash = THashBobJenkins::GetHashString(Memo2->Text);
	// Test the hashes
	if (UnHash == DeHash)
	  ListBox1->Items->Add(Format("Hashes: %s / %s Match",
		ARRAYOFCONST((UnHash, DeHash))));
	else
	  ListBox1->Items->Add(Format("Hashes: %s / %s FAIL",
		ARRAYOFCONST((UnHash, DeHash))));
}
//---------------------------------------------------------------------------
void __fastcall TForm7::btnCompressClick(TObject *Sender)
{
	ListBox1->Clear();
	ListBox1->Items->Add("None");
	TestCompress(zcNone);
	ListBox1->Items->Add("--------");
	ListBox1->Items->Add("Default");
	TestCompress(zcDefault);
	ListBox1->Items->Add("--------");
	ListBox1->Items->Add("Fastest");
	TestCompress(zcFastest);
	ListBox1->Items->Add("--------");
	ListBox1->Items->Add("Max");
	TestCompress(zcMax);
	ListBox1->Items->Add("--------");
}
//---------------------------------------------------------------------------
