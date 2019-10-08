#ifndef FRU_H
#define FRU_H

#ifdef __cplusplus
extern "C" {
#endif

#include <asm/byteorder.h>
#include <stddef.h>
#include <stdint.h>

#include "base.h"

#define PLDM_GET_FRU_RECORD_TABLE_METADATA_RESP_BYTES 19

/** @brief PLDM FRU commands
 */
enum pldm_fru_commands {
	PLDM_GET_FRU_RECORD_TABLE_METADATA = 0X01,
};

/** @struct pldm_get_fru_record_table_metadata_resp
 *
 *  Structure representing PLDM get FRU table metadata response.
 */
struct pldm_get_fru_record_table_metadata_resp {
	uint8_t completion_code;	//!< completion code
	uint8_t fru_data_major_version; //!< The major version of the FRU Record
	uint8_t fru_data_minor_version; //!< The minor version of the FRU Record
	uint32_t
	    fru_table_maximum_size; //!< The size of the largest FRU Record data
	uint32_t fru_table_length; //!< The total length of the FRU Record Table
	uint16_t total_record_set_identifiers; //!< The total number of FRU
					       //!< Record Data structures
	uint16_t
	    total_table_records; //!< The total number of records in the table
	uint32_t
	    checksum; //!< The integrity checksum on the FRU Record Table data
} __attribute__((packed));

/* Requester */

/* GetFRURecordTableMetadata */

/** @brief Create a PLDM request message for GetFRURecordTableMetadata
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in,out] msg - Message will be written to this
 *  @return pldm_completion_codes
 *  @note  Caller is responsible for memory alloc and dealloc of param
 *         'msg.payload'
 */
int encode_get_fru_record_table_metadata_req(uint8_t instance_id,
					     struct pldm_msg *msg);

/** @brief Decode GetFruRecordTable response data
 *
 *  @param[in] msg - Response message
 *  @param[in] payload_length - Length of response message payload
 *  @param[out] completion_code - Pointer to response msg's PLDM completion code
 *  @param[out] fru_data_major_version - Major version of the FRU Record
 *  @param[out] fru_data_minor_version - Minor version of the FRU Record
 *  @param[out] fru_table_maximum_size - Size of the largest FRU Record data
 *  @param[out] fru_table_length - Total length of the FRU Record Table
 *  @param[out] total_Record_Set_Identifiers - Total number of FRU Record Data
 * structures
 *  @param[out] total_table_records - Total number of records in the table
 *  @param[out] checksum - integrity checksum on the FRU Record Table data
 *  @return pldm_completion_codes
 */
int decode_get_fru_record_table_metadata_resp(
    const struct pldm_msg *msg, size_t payload_length, uint8_t *completion_code,
    uint8_t *fru_data_major_version, uint8_t *fru_data_minor_version,
    uint32_t *fru_table_maximum_size, uint32_t *fru_table_length,
    uint16_t *total_record_set_identifiers, uint16_t *total_table_records,
    uint32_t *checksum);

/* Responder */

/* GetFRURecordTableMetadata */

/** @brief Create a PLDM response message for GetFRURecordTableMetadata
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] completion_code - PLDM completion code
 *  @param[in] fru_data_major_version - Major version of the FRU Record
 *  @param[in] fru_data_minor_version - Minor version of the FRU Record
 *  @param[in] fru_table_maximum_size - Size of the largest FRU Record data
 *  @param[in] fru_table_length - Total length of the FRU Record Table
 *  @param[in] total_Record_Set_Identifiers - Total number of FRU Record Data
 * structures
 *  @param[in] total_table_records - Total number of records in the table
 *  @param[in] checksum - integrity checksum on the FRU Record Table data
 *  @param[in,out] msg - Message will be written to this
 *  @return pldm_completion_codes
 *  @note  Caller is responsible for memory alloc and dealloc of param
 *         'msg.payload'
 */

int encode_get_fru_record_table_metadata_resp(
    uint8_t instance_id, uint8_t completion_code,
    uint8_t fru_data_major_version, uint8_t fru_data_minor_version,
    uint32_t fru_table_maximum_size, uint32_t fru_table_length,
    uint16_t total_record_set_identifiers, uint16_t total_table_records,
    uint32_t checksum, struct pldm_msg *msg);

#ifdef __cplusplus
}
#endif

#endif