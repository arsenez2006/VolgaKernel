#pragma once
#include <common/attributes.hpp>
#include <common/types.hpp>

/**
 * @struct boot_info_t
 * @brief Boot info, passed to TSL and kernel
 *
 * @typedef boot_info_t
 * @brief boot_info_t type
 *
 */
typedef struct __packed boot_info_t {
  /**
   * @brief Size of this structure
   *
   */
  dword_t size;

  /**
   * @brief Booted drive info
   *
   */
  struct {
    /**
     * @brief Booted drive GUID
     *
     */
    byte_t GUID[16];
  } boot_drive;

  /**
   * @brief Memory map info
   *
   */
  struct {
    /**
     * @brief Count of memory map entries
     *
     */
    dword_t count;
    /**
     * @brief Size of each memory map entry
     *
     */
    dword_t entry_size;
    /**
     * @brief Physical address to memory map array
     *
     */
    qword_t address;
  } memory_map;

  /**
   * @brief Video info
   *
   */
  struct {
    /**
     * @brief Driver type
     *
     */
    dword_t type;
    /**
     * @brief Physical address to driver info
     *
     */
    qword_t address;
  } video_info;

  /**
   * @brief ACPI tables
   *
   */
  struct {
    /**
     * @brief Address of RSDP
     *
     */
    qword_t rsdp;
  } ACPI;

  /**
   * @brief RAMFS info
   *
   */
  struct {
    /**
     * @brief Physical address of RAMFS
     *
     */
    qword_t address;
  } RAMFS;
} boot_info_t;
