Imports System
Imports System.Globalization
Imports System.Windows.Forms
Imports System.IO.Ports
Imports System.IO
Imports System.Reflection
Imports System.Threading.Thread
Imports Microsoft.VisualBasic
Imports System.Math

Public Class frmComm

    Public Delegate Sub StringSubPointer(ByVal Buffer As String)
    'Public Transmit_Packet_Length As Integer = 6
    'Public Received_Packet_Length = 5
    Public date1 As Date
    Public ms As TimeSpan
    Public Current As Long

    Public RXByteArray(79) As Byte


    Private Function calcVal(A() As Byte, startAddress As Integer, size As Integer)
        Dim V As Double = 0
        Dim fullByte As Integer = 256
        Dim add As Integer
        For add = 0 To size - 1
            V = V + A(startAddress + add) * (fullByte ^ (size - 1 - add))
        Next
        Return V
    End Function

    Private Function ReverseBytes(inArray() As Byte) As Byte()
        Dim temp As Byte
        Dim highCtr As Integer = inArray.Length - 1

        For ctr As Integer = 0 To highCtr \ 2
            temp = inArray(ctr)
            inArray(ctr) = inArray(highCtr)
            inArray(highCtr) = temp
            highCtr -= 1
        Next
        Return inArray
    End Function

    Private Sub frmComm_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load


        Me.Location = New Point((My.Computer.Screen.WorkingArea.Width / 2) - (Me.Width / 2), _
                                My.Computer.Screen.WorkingArea.Height - Me.Height)


        ' Load connected COM ports to list.
        For Each COMString As String In My.Computer.Ports.SerialPortNames
            COMPortsBox.Items.Add(COMString)
        Next

        SerialPort.ReceivedBytesThreshold = 100
        SerialPort.ReadTimeout = 200
        SerialPort.WriteTimeout = 200
        PortStatus.BackColor = Color.Gray
        PortStatus.ForeColor = Color.White
        PortStatus.Text = "Port Closed"
        Port_Open_Close.Text = "Open Port"

        Me.KeyPreview = True

    End Sub

    ' This subroutine is activated when the form is closed. It closes the COM port. Without such a close command,
    '   the garbage collector may close the COM port while it is still in use!
    Private Sub frmEMcontrol_Closing(ByVal sender As Object, ByVal e As System.Windows.Forms.FormClosingEventArgs) Handles MyBase.Closing
        If MessageBox.Show("Close Window?", "GPS Test GUI", _
                           MessageBoxButtons.YesNo, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2) = Windows.Forms.DialogResult.No Then
            e.Cancel = True
        Else
            Try
                If SerialPort.IsOpen Then
                    GC.ReRegisterForFinalize(SerialPort.BaseStream)
                    SerialPort.Close()
                    SerialPort.Dispose()
                End If
            Catch ex As Exception
                MessBox(ex.Message, MessageBoxButtons.OK, MessageBoxIcon.Error)
            End Try
        End If
    End Sub

    Private Sub Port_Open_Close_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Port_Open_Close.Click

        If SerialPort.IsOpen Then

            'While (SerialPort.BytesToRead > 0) ' wait to clean buffer
            'End While

            ' Close port
            Try
                If SerialPort.IsOpen Then
                    GC.ReRegisterForFinalize(SerialPort.BaseStream)
                    SerialPort.Close()
                    SerialPort.Dispose()
                End If
            Catch ex As Exception
                MessBox(ex.Message, MessageBoxButtons.OK, MessageBoxIcon.Error)
            End Try

            PortStatus.BackColor = Color.Gray
            PortStatus.ForeColor = Color.White
            PortStatus.Text = "Port Closed"
            Port_Open_Close.Text = "Open Port"


        Else
            If COMPortsBox.Text = "" Then
                MessBox("Select Port", , _
                        MessageBoxIcon.Information, )
            Else
                SerialPort.PortName = COMPortsBox.Text
                Try
                    SerialPort.Open()
                    GC.SuppressFinalize(SerialPort.BaseStream)
                Catch ex As Exception
                    MessBox(ex.Message, , MessageBoxIcon.Error)
                End Try
                If SerialPort.IsOpen Then
                    'SerialPort.RtsEnable = True
                    'SerialPort.DtrEnable = True
                    SerialPort.DiscardInBuffer()
                    PortStatus.BackColor = Color.LightGreen
                    PortStatus.ForeColor = Color.Black
                    PortStatus.Text = "Port Open"
                    Port_Open_Close.Text = "Close Port"
                End If
            End If
        End If

    End Sub

    Private Sub Receiver(ByVal sender As Object, ByVal e As SerialDataReceivedEventArgs) Handles SerialPort.DataReceived
        Dim RXArray(79) As String
        Dim i As Integer = 0

        Try
            SerialPort.Read(RXByteArray, 0, 80)
            'Sleep(20)
            For i = 0 To 79
                RXArray(i) = Hex(RXByteArray(i))
            Next

        Catch ex As Exception
            MessBox("RX Error:" + vbCrLf + ex.Message + vbCrLf _
                   + "Or - Port was closed while the IB was transmitting", , _
                   MessageBoxIcon.Error)
            ' Reset RXarray when comm breaks
            SerialPort.DiscardInBuffer()
        End Try

        ' Convert the received Char Array to a String
        Dim RxString As String = Strings.Join(RXArray)
        'Sleep(50)

        ' Add time stamp
        date1 = Date.Now
        ms = New TimeSpan(date1.Ticks)
        RxString = date1.ToString("M/dd HH:mm:ss") + " " _
                  + ms.Milliseconds.ToString + vbCrLf + RxString

        ' Put a message with a delegate, which points to the display routine and holds the RxString
        ' on the message queue and return immediately.
        Me.BeginInvoke(New StringSubPointer(AddressOf Display), RxString)

        Me.KeyPreview = True

    End Sub

    Private Sub Display(ByVal Buffer As String)

        ' Write received telemetry to GUI
        Received.AppendText(Buffer)
        Received.AppendText(vbCrLf)

        Dim tmp(7) As Byte
        Dim F00_offset As Integer = 8 'position where F00 starts in RXByteArray


        textAnalog1.Text = RXByteArray(1)
        textAnalog2.Text = RXByteArray(2)
        textAnalog3.Text = RXByteArray(3)

        Dim X As Double = BitConverter.ToSingle(RXByteArray, 8 + F00_offset)
        Dim Y As Double = BitConverter.ToSingle(RXByteArray, 0 + F00_offset)
        Dim Z As Double = BitConverter.ToSingle(RXByteArray, 16 + F00_offset)

        textPosX.Text = X
        textPosY.Text = Y
        textPosZ.Text = Z

        textVelX.Text = BitConverter.ToSingle(RXByteArray, 20 + F00_offset)
        textVelY.Text = BitConverter.ToSingle(RXByteArray, 24 + F00_offset)
        textVelZ.Text = BitConverter.ToSingle(RXByteArray, 28 + F00_offset)


        textYear.Text = BitConverter.ToInt16(RXByteArray, 56 + F00_offset)
        textMonth.Text = RXByteArray(64 + F00_offset)
        textDay.Text = RXByteArray(63 + F00_offset)
        textHour.Text = RXByteArray(65 + F00_offset)
        textMinute.Text = RXByteArray(66 + F00_offset)
        'textSecond.Text = BitConverter.ToDouble(F00, 0)
        textGPSSec.Text = BitConverter.ToSingle(RXByteArray, 48 + F00_offset)
        textGPSWeek.Text = BitConverter.ToInt32(RXByteArray, 52 + F00_offset)

        textNavMode.Text = RXByteArray(60 + F00_offset)
        textGdop.Text = BitConverter.ToSingle(RXByteArray, 32 + F00_offset)
        textPdop.Text = BitConverter.ToSingle(RXByteArray, 36 + F00_offset)
        textVdop.Text = BitConverter.ToSingle(RXByteArray, 40 + F00_offset)
        textNumsats.Text = RXByteArray(61 + F00_offset)
        textTrackType.Text = RXByteArray(62 + F00_offset)
        textDoppClk.Text = BitConverter.ToInt32(RXByteArray, 44 + F00_offset)
        textTimeType.Text = RXByteArray(68 + F00_offset)

        ' from gps interpret code - not sure why, maybe endian / byte order mismatch
        tmp(4) = RXByteArray(0 + F00_offset)
        tmp(5) = RXByteArray(1 + F00_offset)
        tmp(6) = RXByteArray(2 + F00_offset)
        tmp(7) = RXByteArray(3 + F00_offset)
        tmp(0) = RXByteArray(4 + F00_offset)
        tmp(1) = RXByteArray(5 + F00_offset)
        tmp(2) = RXByteArray(6 + F00_offset)
        tmp(3) = RXByteArray(7 + F00_offset)
        textSecond.Text = BitConverter.ToDouble(tmp, 0)

        ECEFtoLLA(X, Y, Z)


    End Sub

    Private Sub ECEFtoLLA(X As Double, Y As Double, Z As Double)

        Dim Lon, Lat, Alt, N, Alt_old, Lat_old As Double
        Const RadtoDeg As Double = 180 / PI

        ' WGS84
        Dim eccSquared As Double = 0.00669437999014
        Dim a As Double = 6378137.0
        Dim p As Double = Sqrt(X ^ 2 + Y ^ 2)

        Lat = Atan2(Z, p * (1 - eccSquared))
        Alt = 0

        ' Iterate
        For i = 0 To 5
            N = a / Sqrt(1 - eccSquared * Sin(Lat) * Sin(Lat))
            Alt_old = Alt
            Alt = p / Cos(Lat) - N
            Lat_old = Lat
            Lat = Atan2(Z, p * (1 - eccSquared * N / (N + Alt)))

            If (Abs(Alt - Alt_old) < 0.000000001) And (Abs(Lat - Lat_old) < a * 0.000000001) Then Exit For

        Next

        Lon = Atan2(Y, X)
        If Lon < 0 Then Lon += 2 * PI

        textLon.Text = Lon * RadtoDeg
        textLat.Text = Lat * RadtoDeg
        textAlt.Text = Alt

    End Sub

    Private Sub ClearButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ClearButton.Click
        ' Clear received text
        Received.Clear()
        If SerialPort.IsOpen Then
            SerialPort.DiscardInBuffer()
        End If
    End Sub

    Private Sub AboutToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles AboutToolStripMenuItem.Click
        ' Select About from menu
        ' Check if published
        If System.Deployment.Application.ApplicationDeployment.IsNetworkDeployed Then
            Dim ver As New String(System.Deployment.Application.ApplicationDeployment. _
                                  CurrentDeployment.CurrentVersion.ToString)
            MessBox("GPS Test GUI" + vbCrLf + _
                   "Cornell University - Fall 2011" + vbCrLf + "Version: " + ver, , _
                   MessageBoxIcon.Information)
        Else
            MessBox("GPS Test GUI" + vbCrLf + "Cornell University - Fall 2011", , _
                    MessageBoxIcon.Information)
        End If
    End Sub

    Private Sub RefreshPortsListToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles RefreshPortsListToolStripMenuItem.Click

        COMPortsBox.Text = ""
        COMPortsBox.Items.Clear()

        ' Load connected COM ports to list.
        For Each COMString As String In My.Computer.Ports.SerialPortNames
            COMPortsBox.Items.Add(COMString)
        Next

    End Sub

    Private Sub btnSaveAs_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnSaveAs.Click
        Dim SaveFileDialog1 As New SaveFileDialog()


        If SerialPort.IsOpen Then

            ' Close port
            Try
                If SerialPort.IsOpen Then
                    GC.ReRegisterForFinalize(SerialPort.BaseStream)
                    SerialPort.Close()
                    SerialPort.Dispose()
                End If
            Catch ex As Exception
                MessBox(ex.Message, MessageBoxButtons.OK, MessageBoxIcon.Error)
            End Try

            PortStatus.BackColor = Color.Gray
            PortStatus.ForeColor = Color.White
            PortStatus.Text = "Port Closed"
            Port_Open_Close.Text = "Open Port"

        End If ' port is closed

        If Received.Text = "" Then
            MessBox("Nothing to save...", , MessageBoxIcon.Information)
        Else

            Try
                ' Save received text to file
                SaveFileDialog1.Filter = "Text Files (*.txt)|*.txt"
                SaveFileDialog1.Title = "Save Received data As"
                SaveFileDialog1.FileName = "Telemetry"
                ' files are in folder - desktop\Telemetry
                SaveFileDialog1.InitialDirectory = _
                Path.Combine(My.Computer.FileSystem.SpecialDirectories.Desktop, "Telemetry")

                If SaveFileDialog1.ShowDialog() = System.Windows.Forms.DialogResult.OK _
                    And SaveFileDialog1.FileName.Length > 0 Then

                    ' Write received text
                    My.Computer.FileSystem.WriteAllText(SaveFileDialog1.FileName, Received.Text, False) ' Overwrite file
                    ' Clear text
                    Received.Clear()
                End If
            Catch ex As Exception
                MessBox(ex.Message, , MessageBoxIcon.Error)
                Exit Sub
            End Try
        End If

    End Sub


    Public Function MessBox(ByVal Msgtext As String, _
                        Optional ByVal Boxtype As MessageBoxButtons = MessageBoxButtons.OK, _
                        Optional ByVal Boxicon As MessageBoxIcon = MessageBoxIcon.None, _
                        Optional ByVal Defbutton As MessageBoxDefaultButton = MessageBoxDefaultButton.Button1) _
                        As DialogResult

        Return MessageBox.Show(Msgtext, "GPS Test GUI", Boxtype, Boxicon, Defbutton)

    End Function

    Private Sub ExitToolStripMenuItem1_Click(sender As System.Object, e As System.EventArgs) Handles ExitToolStripMenuItem1.Click
        Me.Close()
    End Sub

End Class

' to do:
' 
' which 'seconds' to use?
' calculate lla pos from ecef pos?
