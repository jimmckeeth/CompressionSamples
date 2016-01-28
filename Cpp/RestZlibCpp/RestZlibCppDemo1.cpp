//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "RestZlibCppDemo1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm17 *Form17;
//---------------------------------------------------------------------------
__fastcall TForm17::TForm17(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm17::RESTRequest1AfterExecute(TCustomRESTRequest *Sender)
{
	DecodeRestResponse(RESTResponse1);
}
//---------------------------------------------------------------------------
void __fastcall TForm17::Button1Click(TObject *Sender)
{
	RESTRequest1->Execute();
}
//---------------------------------------------------------------------------
