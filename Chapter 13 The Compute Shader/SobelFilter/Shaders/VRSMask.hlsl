//=============================================================================
// Performs edge detection using Sobel operator.
//=============================================================================

Texture2D gInput            : register(t0);
RWTexture2D<uint> gOutput : register(u0);


[numthreads(16, 16, 1)]
void VRSMask(int3 dispatchThreadID : SV_DispatchThreadID)        
{
if(dispatchThreadID.x < dispatchThreadID.y)
	gOutput[dispatchThreadID.xy] = 10;
else
	gOutput[dispatchThreadID.xy] = 1;
}
