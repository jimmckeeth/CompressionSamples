unit RestDecompress;

interface

uses
  System.SysUtils, System.Types, System.Classes, IPPeerClient, REST.Client;

procedure DecodeRestResponse(ARestResponse: TRESTResponse);

implementation

uses
  System.Zlib,
  IdBaseComponent, IdException, IdZLibCompressorBase, IdCompressorZLib;

  type // protected mode work around
  TProtectedRESTResponse = class(TRESTResponse)
  end;


procedure DecodeRestResponse(ARestResponse: TRESTResponse);
var
  LCompressed: TMemoryStream;
  LDecompressed: TStringStream;
  LDecompress: TIdCompressorZLib;
begin
  if Length(ARestResponse.ContentEncoding) = 0 then exit;

  LCompressed := nil;
  LDecompressed := nil;
  LDecompress := nil;
  try
    LCompressed := TMemoryStream.Create;
    LDecompressed := TStringStream.Create;

    LCompressed.WriteData(ARESTResponse.RawBytes, Length(ARESTResponse.RawBytes));
    LCompressed.Position := 0;

    // Use the Indy decompression libraries because the HTTP stream doesn't
    //   have the proper headers that System.ZLib looks for.

    LDecompress :=TIdCompressorZLib.Create();

    if ARestResponse.ContentEncoding = 'gzip' then
      LDecompress.DecompressGZipStream(LCompressed, LDecompressed)
    else if ARestResponse.ContentEncoding = 'deflate' then
    begin
      // Due to variations in the deflate server side implementations,
      //   this rarely works, but is here for completeness and just in case
      LDecompress.DecompressHTTPDeflate(LCompressed, LDecompressed);
    end;

    TProtectedRESTResponse(ARESTResponse).SetContent(LDecompressed.DataString);
  finally
    LDecompressed.Free;
    LCompressed.Free;
    LDecompress.Free;
  end;
end;

end.
