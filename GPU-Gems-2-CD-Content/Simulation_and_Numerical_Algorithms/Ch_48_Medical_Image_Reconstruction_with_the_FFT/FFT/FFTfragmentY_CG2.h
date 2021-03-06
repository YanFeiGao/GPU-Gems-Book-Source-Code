/***************************************************************************
*        FILE NAME:  FFTfragmentY_CG2.h
*
* ONE LINE SUMMARY:
*        This file contains the shader method 2, y FFT
*        
*        Thilaka Sumanaweera
*        Siemens Medical Solutions USA, Inc.
*        1230 Shorebird Way
*        Mountain View, CA 94039
*        USA
*        Thilaka.Sumanaweera@siemens.com
*
* DESCRIPTION:
*
*****************************************************************************
* REVISION HISTORY:
* Rev     When      Who         What
* V1      15Dec2004 Thilaka     Created.
****************************************************************************/
const char *FFTfragmentY_CG2 = "\n"
"void FragmentProgram(in float4 TexCoordRect0 : TEXCOORD0,\n"
"                     in float4 TexCoordRect1 : TEXCOORD1,\n"
"                     out float4 sColor0 : COLOR0,\n"
"                     out float4 sColor1 : COLOR1,\n"
"                     out float4 sColor2 : COLOR2,\n"
"                     out float4 sColor3 : COLOR3,\n"
"                     const uniform samplerRECT Real1,\n"
"                     const uniform samplerRECT Imag1,\n"
"                     const uniform samplerRECT Real2,\n"
"                     const uniform samplerRECT Imag2)\n"
"{\n"
"	float4 WR;\n"
"	float4 WI;\n"
"	float4 i0 = float4(TexCoordRect0.z, 0.0, 0.0, 0.0);\n"
"	float4 i1 = float4(TexCoordRect0.w, 0.0, 0.0, 0.0);\n"
"	sincos(TexCoordRect1.x, WI.x, WR.x);\n"
"\n"
"	float2 Res;\n"
"	float2 r1     = float2(TexCoordRect0.x, i0.x);\n"
"	float2 r2     = float2(TexCoordRect0.x, i1.x);\n"
"\n"
"	float4 InputX1 = texRECT(Real1, r1);\n"
"	float4 InputY1 = texRECT(Imag1, r1);\n"
"\n"
"	float4 InputX2 = texRECT(Real1, r2);\n"
"	float4 InputY2 = texRECT(Imag1, r2);\n"
"\n"
"	Res.x = WR.x*InputX2.x - WI.x*InputY2.x;\n"
"	Res.y = WI.x*InputX2.x + WR.x*InputY2.x;\n"
"\n"
"	sColor0.x = InputX1.x + Res.x;\n"
"	sColor1.x = InputY1.x + Res.y;\n"
"\n"
"	float4 InputX1_ = texRECT(Real2, r1);\n"
"	float4 InputY1_ = texRECT(Imag2, r1);\n"
"\n"
"	float4 InputX2_ = texRECT(Real2, r2);\n"
"	float4 InputY2_ = texRECT(Imag2, r2);\n"
"\n"
"	Res.x = WR.x*InputX2_.x - WI.x*InputY2_.x;\n"
"	Res.y = WI.x*InputX2_.x + WR.x*InputY2_.x;\n"
"\n"
"	sColor2.x = InputX1_.x + Res.x;\n"
"	sColor3.x = InputY1_.x + Res.y;\n"
"}\n";
