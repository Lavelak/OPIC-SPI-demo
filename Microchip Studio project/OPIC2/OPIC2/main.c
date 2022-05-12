#include <atmel_start.h>
#include <stdlib.h>
#include <string.h>



int CAM_FRAME1_LEN = 4;
// Over current protection mechanism. Values configure over current event counter threshold for power off.
uint8_t cam_reg_frame1[4][3] = {
	{0x93, 0x10, 0xFF}, // for 2.1V (byte1)
	{0x93, 0x11, 0xFF}, // for 2.1V (byte0)
	{0x93, 0x12, 0xFF}, // for 3.3V (byte1)
	{0x93, 0x13, 0xFF}  // for 3.3V (byte0)
};

int CAM_FRAME2_LEN = 24;
uint8_t cam_reg_frame2[24][3] = {
	{0x93, 0x08, 0xff}, // frame tag
	{0x93, 0x09, 0x77}, // frame tag
	{0x93, 0x0a, 0xaa}, // frame tag
	{0x93, 0x0b, 0xde}, // frame tag
	{0x93, 0x0c, 0xad}, // frame tag
	{0x93, 0x0d, 0xbe}, // frame tag
	{0x93, 0x0e, 0xef}, // frame tag
	{0x93, 0x0f, 0x00}, // frame tag
	{0x93, 0x02, 0x01}, // frame count
	{0x93, 0x15, 0x00}, // x_start of crop window (byte1)
	{0x93, 0x16, 0x00}, // x_start of crop window (byte0)
	{0x93, 0x17, 0xff}, // width (byte1)
	{0x93, 0x18, 0x07}, // width (byte0)
	{0x93, 0x19, 0x00}, // y_start of crop window (byte1)
	{0x93, 0x1a, 0x00}, // y_start of crop window (byte0)
	{0x93, 0x1b, 0xff}, // height (byte1)
	{0x93, 0x1c, 0x07}, // height (byte0)
	{0x93, 0x23, 0x29}, // exposure time (byte2)
	{0x93, 0x24, 0x00}, // exposure time (byte1)
	{0x93, 0x25, 0x00}, // exposure time (byte0)
	{0x93, 0x03, 0x00}, // delay period between frames (if more than one) (byte3)
	{0x93, 0x04, 0x50}, // delay period between frames (if more than one) (byte2)
	{0x93, 0x05, 0xc3}, // delay period between frames (if more than one) (byte1)
	{0x93, 0x06, 0x00}  // delay period between frames (if more than one) (byte0)
};

int CAM_ARRAY_LEN = 34;
uint8_t cam_reg_array[34][3] = {
	{0x93, 0x22, 0x09},
	{0x93, 0x01, 0x58},	  // capture test image
	//{0x93, 0x01, 0x48}, // capture image 
	{0x9b, 0x71, 0x00},
	{0x9b, 0x73, 0x01},
	{0x9b, 0x72, 0x03},
	{0x9b, 0x74, 0x09},
	{0x9b, 0x6f, 0x01},
	{0x9b, 0x70, 0x00},
	{0x9b, 0x75, 0x08},
	{0x9b, 0x50, 0x55},
	{0x9b, 0x51, 0x55},
	{0x9b, 0x52, 0x07},
	{0x93, 0x07, 0x02},
	{0x9b, 0x62, 0x6d},
	{0x9b, 0x63, 0x6d},
	{0x9b, 0x49, 0x14},
	{0x9b, 0x48, 0x02},
	{0x9b, 0x29, 0x04},
	{0x9b, 0x4d, 0x00},
	{0x9b, 0x54, 0x04},
	{0x9b, 0x55, 0x01},
	{0x9b, 0x56, 0x0e},
	{0x9b, 0x57, 0x0c},
	{0x9b, 0x58, 0x40},
	{0x9b, 0x5b, 0x40},
	{0x9b, 0x5e, 0x65},
	{0x9b, 0x5f, 0x6a},
	{0x9b, 0x66, 0x01},
	{0x9b, 0x76, 0x01},
	{0x9b, 0x7b, 0x62},
	{0x9b, 0x67, 0x3b},
	{0x9b, 0x64, 0xc3},
	{0x9b, 0x65, 0x3f},
	{0x9b, 0x09, 0x08}
};

int opic_spi_write_reg(struct io_descriptor *io, uint8_t* cmd_addr_data);

int opic_spi_read_reg(struct io_descriptor *io, uint8_t* cmd_addr_data, uint8_t* data_out);

int opic_spi_read_sdram_word(struct io_descriptor *io, uint8_t query_addr, uint8_t* tgt1, uint8_t* tgt2);

int opic_clear_sdram(struct io_descriptor *io);

int opic_config_picture(struct io_descriptor *io);

int opic_take_picture(struct io_descriptor *io);

int opic_stream_frame(struct io_descriptor *io);


int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	struct io_descriptor *io;
	spi_m_sync_get_io_descriptor(&SPI_0, &io);
	spi_m_sync_enable(&SPI_0);

	
	delay_ms(1000);
	
	uint8_t vearsion_reg[3] = {0x92, 0x00, 0x00};
	uint8_t version[1];
	opic_spi_read_reg(io, vearsion_reg, version);
	
	// sends Clear SDRAM command
	int r = opic_clear_sdram(io);
	if(r != 0){
		delay_ms(1000);
	}
	
	// configures OPIC camera module for image capture
	r = opic_config_picture(io);
	if(r != 0){
		delay_ms(1000);
	}
	
	// sends command to capture an image
	delay_ms(50);
	r = opic_take_picture(io);
	if(r != 0){
		delay_ms(1000);
	}
	
	delay_ms(1000);
	
	// verify that image is captured by reading frame header from SDRAM
	uint8_t tgt[1024];
	for (int i = 0; i<28; i++){
		uint8_t addr = i*2;
		r = opic_spi_read_sdram_word(io, addr, tgt+i*2, tgt+i*2+1);
		if(r != 0){
			delay_ms(1000);
		}
	}
	delay_ms(1000);
	
	
	opic_stream_frame(io);
	
	// tests for register read & write commands
	static uint8_t buffer[12];
	int c = 0;
	while (1) {
		buffer[0] = 0x92;
		buffer[1] = 0x00;
		buffer[2] = 0x00;
		
		buffer[3] = 2;
		buffer[4] = 2;
		buffer[5] = 2;
		
		io_write(io, buffer, 3);
		io_read(io, buffer+3, 3);
		delay_ms(200);
		
		
		
		buffer[0] = 0x93;
		buffer[1] = 0x10;
		buffer[2] = 0x77+c;
		
		buffer[3] = 0x00;
		buffer[4] = 0x00;
		buffer[5] = 0x00;
		io_write(io, buffer, 3);
		io_read(io, buffer+3, 3);
		delay_ms(200);
		
		
		
		buffer[0] = 0x92;
		buffer[1] = 0x10;
		buffer[2] = 0x00;
		
		buffer[3] = 0x00;
		buffer[4] = 0x00;
		buffer[5] = 0x00;
		io_write(io, buffer, 3);
		io_read(io, buffer+3, 3);
		delay_ms(200);
		
		c++;
	}
}

int opic_spi_write_reg(struct io_descriptor *io, uint8_t* cmd_addr_data){
	uint8_t spoof[8];
	io_write(io, cmd_addr_data, 3);
	io_read(io, spoof, 3);
	int comp1 = spoof[0] == cmd_addr_data[1];
	int comp2 = spoof[1] == cmd_addr_data[2];
	if (!(comp1 && comp2)){
		return -1;
	}
	return 0;
}

int opic_spi_read_reg(struct io_descriptor *io, uint8_t* cmd_addr_data, uint8_t* data_out){
	uint8_t spoof[8];
	io_write(io, cmd_addr_data, 3);
	io_read(io, spoof, 3);
	int comp1 = spoof[0] == cmd_addr_data[1];
	int comp2 = spoof[1] == cmd_addr_data[2];
	if (!(comp1 && comp2)){
		return -1;
	}
	*data_out = spoof[2];
	return 0;
}


int opic_spi_read_sdram_word(struct io_descriptor *io, uint8_t query_addr, uint8_t* tgt1, uint8_t* tgt2){
	uint8_t spoof[8] = {0,0,0,0,0,0,0,0};
	uint8_t qry[8] = {0,0,0,0,0,0,0,0};
	qry[0] = 0xAA;
	qry[1] = query_addr;
	qry[2] = 0x00;
	io_write(io, qry, 3);
	io_read(io, spoof, 3);
	int comp1 = spoof[0] == query_addr;
	if (!comp1){
		return -1;
	}
	*tgt1 = spoof[1];
	*tgt2 = spoof[2];
	return 0;
}


int opic_clear_sdram(struct io_descriptor *io){
	uint8_t clear_reg[3] = {0xA3, 0x02, 0x08};
	int r = opic_spi_write_reg(io, clear_reg);
	if(r != 0){
		return -1;
	}
	return 0;
}



int opic_config_picture(struct io_descriptor *io){
	int r = 0;
	for (int i=0; i<CAM_FRAME1_LEN; i++){
		uint8_t* buff = cam_reg_frame1[i];
		r = opic_spi_write_reg(io, buff);
		if(r != 0){
			return -1;
		}
	}
	for (int i=0; i<CAM_ARRAY_LEN; i++){
		uint8_t* buff = cam_reg_array[i];
		r = opic_spi_write_reg(io, buff);
		if(r != 0){
			return -1;
		}
	}
	for (int i=0; i<CAM_FRAME2_LEN; i++){
		uint8_t* buff = cam_reg_frame2[i];
		r = opic_spi_write_reg(io, buff);
		if(r != 0){
			return -1;
		}
	}
	return 0;
}


int opic_take_picture(struct io_descriptor *io){
	uint8_t shoot_reg[3] = {0x93, 0x07, 0x01};
	int r = opic_spi_write_reg(io, shoot_reg);
	if(r != 0){
		return -1;
	}
	return 0;
}

int opic_stream_frame(struct io_descriptor *io){
	delay_ms(200);
	uint8_t spoof[8];
	uint8_t header[28*2];
	uint8_t frame[100];
	//start streaming command
	uint8_t stream_reg[3] = {0x84, 0x00, 0x00};
	uint8_t stop_stream_reg[3] = {0x80, 0x00, 0x00};
	delay_ms(200);
	io_write(io, stream_reg, 3);
	delay_ms(200);
	io_read(io, header, 28*2);
	delay_ms(200);
	io_read(io, frame, 100);
	delay_ms(200);
	// stop streaming command
	io_write(io, stop_stream_reg, 3);
	
	return 0;
}