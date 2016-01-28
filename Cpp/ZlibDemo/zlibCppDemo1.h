//---------------------------------------------------------------------------

#ifndef zlibCppDemo1H
#define zlibCppDemo1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <System.IOUtils.hpp>
#include <System.Hash.hpp>
#include <System.TypInfo.hpp>
#include <System.ZLib.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <memory>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
	TTabControl *TabControl1;
	TTabItem *TabItem1;
	TMemo *Memo1;
	TTabItem *TabItem2;
	TListBox *ListBox1;
	TTabItem *TabItem3;
	TMemo *Memo2;
	TLayout *Layout1;
	TButton *btnCompress;
	void __fastcall btnCompressClick(TObject *Sender);
private:	// User declarations
    void __fastcall TestCompress(TZCompressionLevel ACompressionLevel);
public:		// User declarations
	__fastcall TForm7(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif
