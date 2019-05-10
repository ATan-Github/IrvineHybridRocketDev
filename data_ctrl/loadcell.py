#!/usr/bin/env python
# encoding: utf-8
"""
********************************************
* File Name : loadcell.py

* Created By : Shirley Shah

* Creation Date : 04-30-2019

* Last Modified : 04-30-2019::19:04:32 PDT

* Purpose : Take data from load cell to find force
********************************************
"""

#!/usr/bin/python3

import time

import spidev



spi_ch = 0


# Enable SPI

spi = spidev.SpiDev(0, spi_ch)

spi.max_speed_hz = 1200000


msg =[0b00001100, 0b0000000, 0b00000000]

//message sent to chip select


data =open("ds1.txt", "a")


timevar =0

while(timevar <= 5.0):

     reply = spi.xfer2(msg) //spi method

     data.write(str(reply) +" "+  str(time.time())+"\n") // reply and time is logged



    # print(time.time())

     time.sleep(.03)

     timevar = timevar+0.03


data.close()



def main():
    pass



if __name__ == '__main__':
    main()
