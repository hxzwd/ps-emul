#include "pscx_bios.h"

#include <fstream>
#include <iterator>
#include "stdint.h"

#include "stdlib.h"
#include "stdio.h"
//??
//------------------------------------------------
// TODO : to implement the loadBios function.
// It should load the BIOS binary file into array of bytes u8 (m_data).
//
// Rust:
// pub fn new(path: &Path) -> Result<Bios> {
//    let file = try!(File::open(path));
//
//    let mut data = Vec::new();
//
//    Load the BIOS
//    try!(file.take(BIOS_SIZE).read_to_end(&mut data));
//
//    if data.len() == BIOS_SIZE as usize {
//       Ok(Bios { data: data })
//    } else {
//       Err(Error::new(ErrorKind::InvalidInput,
//                      "Invalid_BIOS_size"))
//    } 
//--------------------------------------------------
//??
Bios::BiosState Bios::loadBios(std::string path)
{
	// Fixme

	FILE *file;
	if((file  = fopen(path.c_str(), "rb")) == NULL)
	{
		return BIOS_STATE_INCORRECT_FILENAME;
	}

	std::vector<uint8_t> data;

	size_t num;
	uint32_t len = m_range.m_length;
	uint8_t tmp_byte;
	size_t size_of_elements = 1;
	size_t num_of_elements = 1;
	while(len--)
	{
		num = fread((void *)&tmp_byte, size_of_elements, num_of_elements, file);
		m_data.push_back(tmp_byte);
	}

	fclose(file);


	if(true)
	{
		return BIOS_STATE_SUCCESS;
	}
	else
	{
		return BIOS_STATE_INVALID_BIOS_SIZE;
	}
}

uint32_t Bios::load32(uint32_t offset)
{
	uint32_t b0 = m_data[offset + 0];
	uint32_t b1 = m_data[offset + 1];
	uint32_t b2 = m_data[offset + 2];
	uint32_t b3 = m_data[offset + 3];

	return b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
}
