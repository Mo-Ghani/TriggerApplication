#ifndef CUDA_CORE_H
#define CUDA_CORE_H
//
// include files
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <vector>
#include <helper_cuda.h>
#include <sys/time.h>
#include <library_daq.h>

// CUDA = Computer Device Unified Architecture

__global__ void kernel_correct_times_and_get_n_pmts_per_time_bin(unsigned int *ct);
__global__ void kernel_correct_times_and_get_n_pmts_per_time_bin_and_direction_bin(unsigned int *ct, bool * dirs);
__global__ void kernel_correct_times(unsigned int *ct);
__global__ void kernel_histo_one_thread_one_vertex( unsigned int *ct, unsigned int *histo );
__global__ void kernel_histo_stride( unsigned int *ct, unsigned int *histo);
__global__ void kernel_histo_iterated( unsigned int *ct, unsigned int *histo, unsigned int offset );
__device__ int get_time_bin();
__device__ int get_time_bin_for_vertex_and_hit(unsigned int vertex_index, unsigned int hit_index);
__device__ float get_light_dx_for_vertex_and_hit(unsigned int vertex_index, unsigned int hit_index);
__device__ float get_light_dy_for_vertex_and_hit(unsigned int vertex_index, unsigned int hit_index);
__device__ float get_light_dz_for_vertex_and_hit(unsigned int vertex_index, unsigned int hit_index);
__device__ float get_light_dr_for_vertex_and_hit(unsigned int vertex_index, unsigned int hit_index);
__global__ void kernel_histo_stride_2d( unsigned int *ct, unsigned int *histo);
__global__ void kernel_histo_per_vertex( unsigned int *ct, unsigned int *histo);
__global__ void kernel_histo_per_vertex_shared( unsigned int *ct, unsigned int *histo);
__global__ void kernel_correct_times_and_get_histo_per_vertex_shared(unsigned int *ct);
__global__ void kernel_correct_times_calculate_averages_and_get_histo_per_vertex_shared(unsigned int *ct,float *dx,float *dy,float *dz, unsigned int *ncone);
__global__ void kernel_nhits(unsigned int *ct, unsigned int start_time, unsigned int nhits_window);

#endif