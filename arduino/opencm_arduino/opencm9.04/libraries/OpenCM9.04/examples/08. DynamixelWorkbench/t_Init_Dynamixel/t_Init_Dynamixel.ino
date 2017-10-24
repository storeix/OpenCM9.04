/*******************************************************************************
* Copyright 2016 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/* Authors: Taehun Lim (Darby) */

#include <DynamixelWorkbench.h>

#define DXL_BUS_SERIAL1 "1"            //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 "2"            //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 "3"            //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
#define DXL_BUS_SERIAL4 "/dev/ttyUSB0" //Dynamixel on Serial3(USART3)  <-OpenCR

DynamixelWorkbench dxl_wb;

void setup() 
{
  Serial.begin(57600);
  while(!Serial);

  uint8_t get_id = 0;
  uint8_t dxl_cnt = 0;
  uint32_t baud[5] = {9600, 57600, 115200, 1000000};
  uint8_t index = 0;

  do
  {
    dxl_wb.begin(DXL_BUS_SERIAL3, baud[index]);
    dxl_cnt = dxl_wb.scan(&get_id, 200);
    index++;
  }while(dxl_cnt != 1);

  dxl_wb.setID(get_id, 1);
  dxl_wb.setBaud(1, 1000000);

  Serial.println(" ");
  Serial.println("ID : 1, Baudrate : 1000000");
}

void loop() 
{

}