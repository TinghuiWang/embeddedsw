// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.1
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
//
// ==============================================================

#ifndef XV_PT3190_H
#define XV_PT3190_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xv_pt3190_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else

/**
 * Encoded Audio Sample Word Length
 */
typedef enum {
    XV_PT3190_16_BITS = 16,
    XV_PT3190_18_BITS = 18,
    XV_PT3190_20_BITS = 20,
    XV_PT3190_22_BITS = 22,
    XV_PT3190_24_BITS = 24
} XV_pt3190_EncAudioLen;

/**
 * Encoded Audio Sampling Frequency
 */
typedef enum {
    XV_PT3190_SRATE_24K  = 0,
    XV_PT3190_SRATE_32K,
    XV_PT3190_SRATE_44K1,
    XV_PT3190_SRATE_48K,
    XV_PT3190_SRATE_96K,
    XV_PT3190_SRATE_192K
} XV_pt3190_AudSampFreq;

/**
 * Audio Samples Per Packet
 */
typedef enum {
    XV_PT3190_6_AUDIO_SAMPLES   = 6,
    XV_PT3190_12_AUDIO_SAMPLES  = 12,
    XV_PT3190_16_AUDIO_SAMPLES  = 16,
    XV_PT3190_48_AUDIO_SAMPLES  = 48,
    XV_PT3190_192_AUDIO_SAMPLES = 192
} XV_pt3190_AudSampPerPckt;

typedef struct {
    XV_pt3190_EncAudioLen AudioSmpWrdLen;
    u8 AudioChannels;
    XV_pt3190_AudSampFreq AudioSampFreq;
}XV_pt3190_AudSrcInfo;

typedef struct {
     u16 PayloadLen;
     u32 SSRC;
     u8  DynamicPayloadType;
     u8  ChannelNum;
     XV_pt3190_AudSampPerPckt AudSampPerPckt;
} XV_pt3190_PcktInfo;

typedef struct {
    u16 DeviceId;
    u32 Ctrl_BaseAddress;
} XV_pt3190_Config;
#endif

typedef struct {
    u32 Ctrl_BaseAddress;
    u32 IsReady;

    XV_pt3190_AudSrcInfo AudStream;
    XV_pt3190_PcktInfo   PcktInfo;
} XV_pt3190;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XV_pt3190_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XV_pt3190_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XV_pt3190_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XV_pt3190_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XV_pt3190_Initialize(XV_pt3190 *InstancePtr, u16 DeviceId);
XV_pt3190_Config* XV_pt3190_LookupConfig(u16 DeviceId);
int XV_pt3190_CfgInitialize(XV_pt3190 *InstancePtr, XV_pt3190_Config *ConfigPtr);
#else
int XV_pt3190_Initialize(XV_pt3190 *InstancePtr, const char* InstanceName);
int XV_pt3190_Release(XV_pt3190 *InstancePtr);
#endif

void XV_pt3190_PcktCfg (XV_pt3190 *InstancePtr);

void XV_pt3190_Start(XV_pt3190 *InstancePtr);
u32 XV_pt3190_IsDone(XV_pt3190 *InstancePtr);
u32 XV_pt3190_IsIdle(XV_pt3190 *InstancePtr);
u32 XV_pt3190_IsReady(XV_pt3190 *InstancePtr);
void XV_pt3190_EnableAutoRestart(XV_pt3190 *InstancePtr);
void XV_pt3190_DisableAutoRestart(XV_pt3190 *InstancePtr);

void XV_pt3190_Set_HwReg_num_samples_V(XV_pt3190 *InstancePtr, u32 Data);
u32 XV_pt3190_Get_HwReg_num_samples_V(XV_pt3190 *InstancePtr);
void XV_pt3190_Set_HwReg_audio_channels_V(XV_pt3190 *InstancePtr, u32 Data);
u32 XV_pt3190_Get_HwReg_audio_channels_V(XV_pt3190 *InstancePtr);
void XV_pt3190_Set_HwReg_payload_length_V(XV_pt3190 *InstancePtr, u32 Data);
u32 XV_pt3190_Get_HwReg_payload_length_V(XV_pt3190 *InstancePtr);
void XV_pt3190_Set_HwReg_channel_number_V(XV_pt3190 *InstancePtr, u32 Data);
u32 XV_pt3190_Get_HwReg_channel_number_V(XV_pt3190 *InstancePtr);
void XV_pt3190_Set_HwReg_payload_type_V(XV_pt3190 *InstancePtr, u32 Data);
u32 XV_pt3190_Get_HwReg_payload_type_V(XV_pt3190 *InstancePtr);
void XV_pt3190_Set_HwReg_ssrc_V(XV_pt3190 *InstancePtr, u32 Data);
u32 XV_pt3190_Get_HwReg_ssrc_V(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_tx_pkt_cnt_V(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_tx_pkt_cnt_V_vld(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_C31_0_V(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_C31_0_V_vld(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_C63_32_V(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_C63_32_V_vld(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_C95_64_V(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_C95_64_V_vld(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_C127_96_V(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_C127_96_V_vld(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_C159_128_V(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_C159_128_V_vld(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_C191_160_V(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_C191_160_V_vld(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_U31_0_V(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_U31_0_V_vld(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_U63_32_V(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_U63_32_V_vld(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_U95_64_V(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_U95_64_V_vld(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_U127_96_V(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_U127_96_V_vld(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_U159_128_V(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_U159_128_V_vld(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_U191_160_V(XV_pt3190 *InstancePtr);
u32 XV_pt3190_Get_HwReg_U191_160_V_vld(XV_pt3190 *InstancePtr);
void XV_pt3190_Set_HwReg_reserved1_V(XV_pt3190 *InstancePtr, u32 Data);
u32 XV_pt3190_Get_HwReg_reserved1_V(XV_pt3190 *InstancePtr);
void XV_pt3190_Set_HwReg_stat_reset_V(XV_pt3190 *InstancePtr, u32 Data);
u32 XV_pt3190_Get_HwReg_stat_reset_V(XV_pt3190 *InstancePtr);

void XV_pt3190_InterruptGlobalEnable(XV_pt3190 *InstancePtr);
void XV_pt3190_InterruptGlobalDisable(XV_pt3190 *InstancePtr);
void XV_pt3190_InterruptEnable(XV_pt3190 *InstancePtr, u32 Mask);
void XV_pt3190_InterruptDisable(XV_pt3190 *InstancePtr, u32 Mask);
void XV_pt3190_InterruptClear(XV_pt3190 *InstancePtr, u32 Mask);
u32 XV_pt3190_InterruptGetEnabled(XV_pt3190 *InstancePtr);
u32 XV_pt3190_InterruptGetStatus(XV_pt3190 *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
