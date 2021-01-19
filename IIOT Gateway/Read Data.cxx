// Code is for - BrokerURl": "link to mqtt broker | "IP": "192.168.1.108", | "Subnetmask": "255.255.255.0", |"Gateway": "192.168.1.1", |"DNS": "8.8.8.8"

String   cmd = "";
cmd = cmd + "5000" ;  // sub HEAD (NOT)
cmd = cmd + "00"  ;  //   network number (NOT)
cmd = cmd + "FF"  ;  //PLC NUMBER
cmd = cmd + "03FF" ; // DEMAND OBJECT MUDULE I/O NUMBER
cmd = cmd + "00" ;  //  DEMAND OBJECT MUDULE DEVICE NUMBER
cmd = cmd + "001C"  ;//  Length of demand data
cmd = cmd + "000A"; //  CPU inspector data
cmd = cmd + "0401"; //  Read command (to read the data from PLC we should “0401”
cmd = cmd + "0000" ;//  Sub command
cmd = cmd +"D*"  ;//   device code
cmd = cmd + "009500"; //adBase 
cmd = cmd + "0001";
//Device No ,It’s a Address every PLC device will have an address
//we need to send the appropriate address to read the data.
