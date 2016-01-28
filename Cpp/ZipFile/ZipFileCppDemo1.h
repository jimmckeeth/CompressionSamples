//---------------------------------------------------------------------------

#ifndef ZipFileCppDemo1H
#define ZipFileCppDemo1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <System.Zip.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <System.IOUtils.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <memory>
//---------------------------------------------------------------------------
class TForm29 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TListBox *ListBox1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations

public:		// User declarations
	__fastcall TForm29(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm29 *Form29;
//---------------------------------------------------------------------------
#endif
