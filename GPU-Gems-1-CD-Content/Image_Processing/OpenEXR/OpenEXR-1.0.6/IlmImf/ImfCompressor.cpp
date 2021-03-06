///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2002, Industrial Light & Magic, a division of Lucas
// Digital Ltd. LLC
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
// *       Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// *       Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// *       Neither the name of Industrial Light & Magic nor the names of
// its contributors may be used to endorse or promote products derived
// from this software without specific prior written permission. 
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
///////////////////////////////////////////////////////////////////////////



//-----------------------------------------------------------------------------
//
//	class Compressor
//
//-----------------------------------------------------------------------------

#include <ImfCompressor.h>
#include <ImfRleCompressor.h>
#include <ImfZipCompressor.h>
#include <ImfPizCompressor.h>

namespace Imf {


Compressor::Compressor (const Header &hdr): _header (hdr) {}


Compressor::~Compressor () {}


Compressor::Format
Compressor::format () const
{
    return XDR;
}


bool	
isValidCompression (Compression c)
{
    switch (c)
    {
      case NO_COMPRESSION:
      case RLE_COMPRESSION:
      case ZIPS_COMPRESSION:
      case ZIP_COMPRESSION:
      case PIZ_COMPRESSION:

	return true;

      default:

	return false;
    }
}


Compressor *
newCompressor (Compression c, int maxScanLineSize, const Header &hdr)
{
    switch (c)
    {
      case RLE_COMPRESSION:

	return new RleCompressor (hdr, maxScanLineSize);

      case ZIPS_COMPRESSION:

	return new ZipCompressor (hdr, maxScanLineSize, 1);

      case ZIP_COMPRESSION:

	return new ZipCompressor (hdr, maxScanLineSize, 16);

      case PIZ_COMPRESSION:

	return new PizCompressor (hdr, maxScanLineSize, 32);

      default:

	return 0;
    }
}


} // namespace Imf
