// Code is for - BrokerURl": "link to mqtt broker | "IP": "192.168.1.108", | "Subnetmask": "255.255.255.0", |"Gateway": "192.168.1.1", |"DNS": "8.8.8.8"

private void btnWrite_Click(object sender, EventArgs e)
{
    if (winsock1.GetState.ToString() != "Connected")
    {
        winsock1Connect();
    }      
    String cmd = "";
    String OutAddress = txtWrite.Text.Trim();
    cmd = "";
    cmd = cmd + "5000";// sub HEAD (NOT)
    cmd = cmd + "00";//   network number (NOT)
    cmd = cmd + "FF";//PLC NUMBER
    cmd = cmd + "03FF";// DEMAND OBJECT MUDULE I/O NUMBER
    cmd = cmd + "00";//  DEMAND OBJECT MUDULE DEVICE NUMBER
    cmd = cmd + "001C";//  Length of demand data
    cmd = cmd + "000A";//  CPU inspector data
    cmd = cmd + "1401";//  Write command
    cmd = cmd + "0000";//  Sub command
    cmd = cmd + "D*";//   device code
    cmd = cmd + "009501"; //adBase 
    cmd = cmd + OutAddress;  //BASE ADDRESS
    winsock1.Send(cmd);
}
