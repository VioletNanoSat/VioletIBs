using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Threading;
using System.IO.Ports;
using System.IO;

namespace GPSIBSim
{
    public partial class Form1 : Form
    {
        Thread rt;
        SerialPort serial = new SerialPort("COM1", 76800);
        string state = "startF00";
        const int f00size = 72;//152;
        const int f03size = 216;//448;
        const int f18size = 192;//194;//192;
        const int f22size = 120;//176;
        const int f23size = 96;
        byte[] f00buff = new byte[f00size];
        byte[] f03buff = new byte[f03size];
        byte[] f18buff = new byte[f18size];
        byte[] f22buff = new byte[f22size];
        byte[] f23buff = new byte[f23size];


        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            setError("");
            setStatusText("");
            int count = 0;
            try{
                if (!serial.IsOpen) {
                    serial.Open();
                }

                char[] ar = textBox1.Text.ToCharArray();
                byte[] b = new byte[1];
                foreach (char c in ar){
                    b[0] = (byte)c;
                    serial.Write(b,0,1);
                    count++;
                }

                setStatusText("Wrote " + count + " bytes to serial.");
            }
            catch (Exception ex)
            {
                setError(ex.Message);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {  
            if (rt == null){
                rt = new Thread(new ThreadStart(callBackReceive));
                try{
                    if (!serial.IsOpen){
                        serial.Open();
                    }
                }catch (Exception ex){
                    setError("Unable to open COM1.");
                    return;
                }

                rt.Start();
            }else{
                try{
                    if (!serial.IsOpen){
                        serial.Open();
                    }
                }catch (Exception ex){
                    setError("Unable to open COM1.");
                    return;
                }
                if (rt.ThreadState == ThreadState.Suspended) {
                    rt.Resume();
                }else{
                    rt.Start();
                }
            }
        }

        public void callBackReceive()
        {
            while (true)
            {
                setStatusText("Listening...");
                FileStream f = new FileStream("gpsdatarecd.txt", FileMode.Append, FileAccess.Write);
                StreamWriter sw = new StreamWriter(f);
                try
                {
                    /*if(state.Equals("startF00") || state.Equals("startF03") || state.Equals("startF18") || state.Equals("startF22") || state.Equals("startF23")){
                        int STX = serial.ReadByte();
                        if(!STX.Equals(0x02)){
                            setError("STX not found in " + state);
                            break;
                        }
                        state = state.Substring(5);// "F00", etc
                    }
                    else if(state.Equals("endF00") || state.Equals("endF03") || state.Equals("endF18") || state.Equals("endF22") || state.Equals("endF23")){
                        int ETX = serial.ReadByte();
                        if(!ETX.Equals(0x03)){
                            setError("ETX not found in " + state);
                            break;
                        }
                        state = "start" + state.Substring(3);// "startF00", etc
                    }
                    else if(state.Equals("F00")){
                        int F = serial.ReadByte();
                        if (!F.Equals((int)'F'))
                        {
                            setError("F not found in F00");
                            state = "startF00";
                            break;
                        }
                        int Zero1 = serial.ReadByte();
                        if (!Zero1.Equals((int)'0'))
                        {
                            setError("First 0 not found in F00");
                            state = "startF00";
                            break;
                        }
                        int Zero2 = serial.ReadByte();
                        if (!Zero2.Equals((int)'0'))
                        {
                            setError("Second 0 not found in F00");
                            state = "startF00";
                        }
                        serial.Read(f00buff,0,f00size);
                        //getAndValidateChecksum(f00buff, state);
                        incRecText("\r\nF00:\r\n");
                        string data = getData(f00buff);
                        incRecText(data);
                        writeToFile("F00", f00buff);
                        state = "endF03";
                    }
                    else if(state.Equals("F03")){
                        int F = serial.ReadByte();
                        if (!F.Equals((int)'F'))
                        {
                            setError("F not found in F03");
                            state = "startF00";
                            break;
                        }
                        int Zero1 = serial.ReadByte();
                        if (!Zero1.Equals((int)'0'))
                        {
                            setError("0 not found in F03");
                            state = "startF00";
                            break;
                        }
                        int Three = serial.ReadByte();
                        if (!Three.Equals((int)'3'))
                        {
                            setError("3 not found in F03");
                            state = "startF00";
                        }
                        serial.Read(f03buff,0,f03size);
                        //getAndValidateChecksum(f03buff, state);
                        incRecText("\r\nF03:\r\n");
                        string data = getData(f03buff);
                        incRecText(data);
                        writeToFile("F03", f03buff);
                        state = "endF18";
                    }
                    else if(state.Equals("F18")){
                        int F = serial.ReadByte();
                        if (!F.Equals((int)'F'))
                        {
                            setError("F not found in F18");
                            state = "startF00";
                            break;
                        }
                        int One = serial.ReadByte();
                        if (!One.Equals((int)'1'))
                        {
                            setError("1 not found in F18");
                            state = "startF00";
                            break;
                        }
                        int Eight = serial.ReadByte();
                        if (!Eight.Equals((int)'8'))
                        {
                            setError("8 not found in F18");
                            state = "startF00";
                        }
                        serial.Read(f18buff,0,f18size);
                        //getAndValidateChecksum(f18buff, state);
                        incRecText("\r\nF18:\r\n");
                        string data = getData(f18buff);
                        incRecText(data);
                        writeToFile("F18", f18buff);
                        state = "endF22";
                    }
                    else if(state.Equals("F22")){
                        int F = serial.ReadByte();
                        if (!F.Equals((int)'F'))
                        {
                            setError("F not found in F22");
                            state = "startF00";
                            break;
                        }
                        int Two1 = serial.ReadByte();
                        if (!Two1.Equals((int)'2'))
                        {
                            setError("First 2 not found in F22");
                            state = "startF00";
                            break;
                        }
                        int Two2 = serial.ReadByte();
                        if (!Two2.Equals((int)'2'))
                        {
                            setError("Second 2 not found in F22");
                            state = "startF00";
                        }
                        serial.Read(f22buff,0,f22size);
                        //getAndValidateChecksum(f22buff, state);
                        incRecText("\r\nF22:\r\n");
                        string data = getData(f22buff);
                        incRecText(data);
                        writeToFile("F22", f22buff);
                        state = "endF23";
                    }
                    else if(state.Equals("F23")){
                        int F = serial.ReadByte();
                        if (!F.Equals((int)'F'))
                        {
                            setError("F not found in F23");
                            state = "startF00";
                            break;
                        }
                        int Two1 = serial.ReadByte();
                        if (!Two1.Equals((int)'2'))
                        {
                            setError("2 not found in F23");
                            state = "startF00";
                            break;
                        }
                        int Three = serial.ReadByte();
                        if (!Three.Equals((int)'3'))
                        {
                            setError("3 not found in F23");
                            state = "startF00";
                        }
                        serial.Read(f23buff,0,f23size);
                        //getAndValidateChecksum(f23buff, state);
                        incRecText("\r\nF23:\r\n");
                        string data = getData(f23buff);
                        incRecText(data);
                        writeToFile("F23", f23buff);
                        state = "endF00";
                     

                    }*/
                    //MessageBox.Show("about to read byte.");
                    int i = serial.ReadByte();
                    byte b = (byte)i;
                    //MessageBox.Show(b.ToString("X"));
                    //incRecText(serial.ReadByte().ToString("X") + " ");

                    sw.Write(b.ToString());

                    //incText("In callback.\r\n");
                }
                catch (Exception e)
                {
                    /*if(state.Equals("startF00")){ // timeout waiting for data to come in
                        continue;
                    }*/
                    MessageBox.Show(e.Message);
                    setError("Error listening; possible timeout.");
                }
                finally
                {
                    sw.Close();
                    f.Close();                    
                }
            } // while
            setStatusText("Not listening.");
        } // callback

        // This delegate enables asynchronous calls for setting
        // the text property on a TextBox control.
        delegate void SetTextCallback(string text);

        private string getData(byte[] array)
        {
            string s = "";
            foreach (byte val in array)
            {
                s += val.ToString("X");
                s += " ";
            }
            return s;
        }

        private void getAndValidateChecksum(byte[] sentence, string state)
        {
            try
            {
                byte[] chk = new byte[2];
                serial.Read(chk,0,2);
                byte[] myChk = new byte[2];
                string sentences = "";
                for (int i = 0; i < sentence.Length; i++)
                {
                    myChk[i % 2] = (byte)(myChk[i % 2] ^ sentence[i]);
                    sentences += myChk[i%2].ToString("X");
                    sentences += " ";
                }
                MessageBox.Show(sentences);
                MessageBox.Show(state + ": " + String.Format("{0:x2} {1:x2} {2:x2} {3:x2}", chk[0], chk[1], myChk[0], myChk[1]));
                /*MessageBox.Show(String.Format("{0:x2}", chk[1]));
                MessageBox.Show(String.Format("{0:x2}", myChk[0]));
                MessageBox.Show(String.Format("{0:x2}", myChk[1]));*/
                if (myChk[0] != chk[0] || myChk[1] != chk[1])
                {
                    MessageBox.Show("Checksum failed."); // this is worth a messagebox because we don't want to miss it
                    /*char[] chk1 = new char[2];
                    char[] myChk1 = new char[2];
                    chk1[0] = (char)chk[0];
                    chk1[1] = (char)chk[1];
                    myChk1[0] = (char)myChk[0];
                    myChk1[1] = (char)myChk[1];*/
                    //StringBuilder sb = new StringBuilder(new String(myChk1));

                    //MessageBox.Show(new String(chk1));
                }

            }
            catch (Exception ex)
            {
                setError(ex.Message);
            }

        }

        private void writeToFile(string prefix, byte[] data)
        {
            DateTime d1 = new DateTime(1970, 1, 1);
            DateTime d2 = new DateTime(DateTime.Now.Year, DateTime.Now.Month, DateTime.Now.Day, 0, 0, 0);
            TimeSpan ts = new TimeSpan(d2.Ticks - d1.Ticks);
            FileStream f = new FileStream(prefix + ts.Ticks.ToString(), FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(f);
            sw.Write(data);
            sw.Close();
            f.Close();
        }

        private void setError(string text)
        {
            // InvokeRequired required compares the thread ID of the
            // calling thread to the thread ID of the creating thread.
            // If these threads are different, it returns true.
            if (this.textBox1.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(setError);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                this.textBox3.Text = text;
            }
        }

        private void incRecText(string text)
        {
            // InvokeRequired required compares the thread ID of the
            // calling thread to the thread ID of the creating thread.
            // If these threads are different, it returns true.
            if (this.textBox1.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(incRecText);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                this.textBox2.Text += text;
            }
        }

        private void setStatusText(string text)
        {
            // InvokeRequired required compares the thread ID of the
            // calling thread to the thread ID of the creating thread.
            // If these threads are different, it returns true.
            if (this.textBox1.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(setStatusText);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                this.textBox4.Text = text;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (rt.ThreadState == ThreadState.Running)
            {
                rt.Suspend();
            }
            if(serial.IsOpen) serial.Close();
            setStatusText("Not listening.");
            setError("");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            int count = 0;
            try
            {
                if (!serial.IsOpen)
                {
                    serial.Open();
                }
                FileStream fs = File.OpenRead(textBox5.Text);
                BinaryReader br = new BinaryReader(fs);

                byte[] b = new byte[1];

                try
                {
                    while (true) // sorry, but this is the simplest way
                    {
                        b[0] = br.ReadByte();
                        serial.Write(b, 0, 1);
                        count++;
                    }
                }
                catch (System.IO.EndOfStreamException)
                {

                }
                catch (Exception ex)
                {
                    //MessageBox.Show("Error reading file.\r\n" + ex.Message);
                    setError(ex.Message);
                }

                br.Close();
                fs.Close();
                //MessageBox.Show("Wrote " + count + " bytes to serial.");
                setStatusText("Wrote " + count + " bytes to serial.");
            }
            catch (Exception ex)
            {
                //MessageBox.Show("Error writing data to serial.\r\n" + ex.Message);
                setError(ex.Message);
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            // create buffer for sentences; need 35 bytes for STX's, ETX's, and checksums
            byte[] sentences = new byte[f00size+f03size+f18size+f22size+f23size+35];
            int checkCounter = 0;
            byte[] checkBuffer = new byte[2];
            sentences[0] = 0x02;
            sentences[f00size+6] = 0x03;
            sentences[1] = 70;
            sentences[2] = 48;
            sentences[3] = 48;
            sentences[4] = 0xDE;
            sentences[5] = 0xAD;
            sentences[6] = 0xBE;
            sentences[7] = 0xEF;
            sentences[8] = 0xAC;
            sentences[9] = 0xED;
            sentences[10] = 0xC0;
            sentences[11] = 0xDE;
            for (int i = 0; i < f00size; i++)
            {
            //   sentences[i+4] = (byte)(i+1);
                checkBuffer[checkCounter%2] ^= sentences[i+4];
                checkCounter++;
            }
            sentences[f00size+4] = checkBuffer[0];
            sentences[f00size+5] = checkBuffer[1];
            checkCounter = 0;
            checkBuffer[0] = 0;
            checkBuffer[1] = 0;
            sentences[f00size+7] = 0x02;
            sentences[f00size+f03size+13] = 0x03;
            sentences[f00size + 8] = 70;
            sentences[f00size + 9] = 48;
            sentences[f00size + 10] = 48 + 3;
            for(int i = 0; i < f03size; i++){
                sentences[i+f00size+11] = (byte)(i+1);
                checkBuffer[checkCounter%2] ^= (byte)(i+1);
                checkCounter++;
            }
            sentences[f00size+f03size+11] = checkBuffer[0];
            sentences[f00size+f03size+12] = checkBuffer[1];
            checkCounter = 0;
            checkBuffer[0] = 0;
            checkBuffer[1] = 0;
            sentences[f00size+f03size+14] = 0x02;
            sentences[f00size+f03size+f18size+20] = 0x03;
            sentences[f00size + f03size + 15] = 70;
            sentences[f00size + f03size + 16] = 48 + 1;
            sentences[f00size + f03size + 17] = 48 + 8;
            for(int i = 0; i < f18size; i++){
                sentences[i+f00size+f03size+18] = (byte)(i+1);
                checkBuffer[checkCounter%2] ^= (byte)(i+1);
                checkCounter++;
            }
            sentences[f00size+f03size+f18size+18] = checkBuffer[0];
            sentences[f00size+f03size+f18size+19] = checkBuffer[1];
            checkCounter = 0;
            checkBuffer[0] = 0;
            checkBuffer[1] = 0;
            sentences[f00size+f03size+f18size+21] = 0x02;
            sentences[f00size+f03size+f18size+f22size+27] = 0x03;
            sentences[f00size + f03size + f18size + 22] = 70;
            sentences[f00size + f03size + f18size + 23] = 48 + 2;
            sentences[f00size + f03size + f18size + 24] = 48 + 2;
            for(int i = 0; i < f22size; i++){
                sentences[i+f00size+f03size+f18size+25] = (byte)(i+1);
                checkBuffer[checkCounter%2] ^= (byte)(i+1);
                checkCounter++;
            }
            sentences[f00size+f03size+f18size+f22size+25] = checkBuffer[0];
            sentences[f00size+f03size+f18size+f22size+26] = checkBuffer[1];
            checkCounter = 0;
            checkBuffer[0] = 0;
            checkBuffer[1] = 0;
            sentences[f00size+f03size+f18size+f22size+28] = 0x02;
            sentences[f00size+f03size+f18size+f22size+f23size+34] = 0x03;
            sentences[f00size + f03size + f18size + f22size + 29] = 70;
            sentences[f00size + f03size + f18size + f22size + 30] = 48 + 2;
            sentences[f00size + f03size + f18size + f22size + 31] = 48 + 3;
            for(int i = 0; i < f23size; i++){
                sentences[i+f00size+f03size+f18size+f22size+32] = (byte)(i+1);
                checkBuffer[checkCounter%2] ^= (byte)(i+1);
                checkCounter++;
            }
            sentences[f00size+f03size+f18size+f22size+f23size+32] = checkBuffer[0];
            sentences[f00size+f03size+f18size+f22size+f23size+33] = checkBuffer[1];
            checkCounter = 0;
            checkBuffer[0] = 0;
            checkBuffer[1] = 0;
            FileStream fs = new FileStream("testdata.dat", FileMode.Create);
            fs.Write(sentences, 0, sentences.Length);
            fs.Close();
        }
    }
}