private void Form1_Load(object sender, EventArgs e)
{
    winsock1Connect();
    winsock1.DataArrival += 
      new MelsecPLC.Winsock.DataArrivalEventHandler(winsock1_DataArrival);
    timer1.Enabled = true;
    timer1.Start();
}

private void winsock1Connect()
{
    try
    {
        if (winsock1.GetState.ToString() != "Connected")
        {

            winsock1.LocalPort = 1027;

            winsock1.RemoteIP ="192.168.1.108";
            int a = 8000;

            winsock1.RemotePort = 8000;

            winsock1.Connect();
        }
    }
    catch (Exception ex)
    {
    }
}
