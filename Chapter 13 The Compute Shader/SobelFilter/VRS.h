#pragma once

#include "../../Common/d3dUtil.h"

class VRSPass
{
public:
	VRSPass(ID3D12Device* device,
		UINT width, UINT height,
		DXGI_FORMAT format);

	VRSPass(const VRSPass& rhs) = delete;
	VRSPass& operator=(const VRSPass& rhs) = delete;
	~VRSPass() = default;

	CD3DX12_GPU_DESCRIPTOR_HANDLE OutputSrv();

	UINT DescriptorCount()const;

	void BuildDescriptors(
		CD3DX12_CPU_DESCRIPTOR_HANDLE hCpuDescriptor,
		CD3DX12_GPU_DESCRIPTOR_HANDLE hGpuDescriptor,
		UINT descriptorSize);

	void OnResize(UINT newWidth, UINT newHeight);

	void Execute(
		ID3D12GraphicsCommandList* cmdList,
		ID3D12RootSignature* rootSig,
		ID3D12PipelineState* pso,
		CD3DX12_GPU_DESCRIPTOR_HANDLE input);
	Microsoft::WRL::ComPtr<ID3D12Resource> GetOutput();

private:
	void BuildDescriptors();
	void BuildResource();

private:

	ID3D12Device* md3dDevice = nullptr;

	UINT mWidth = 0;
	UINT mHeight = 0;
	DXGI_FORMAT mFormat = DXGI_FORMAT_R8_UINT;

	CD3DX12_CPU_DESCRIPTOR_HANDLE mhCpuSrv;
	CD3DX12_CPU_DESCRIPTOR_HANDLE mhCpuUav;

	CD3DX12_GPU_DESCRIPTOR_HANDLE mhGpuSrv;
	CD3DX12_GPU_DESCRIPTOR_HANDLE mhGpuUav;

	Microsoft::WRL::ComPtr<ID3D12Resource> mOutput = nullptr;
};

