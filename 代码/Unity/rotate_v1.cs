using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using System.IO.Ports;

public class rotate : MonoBehaviour
{
    // Start is called before the first frame update
    public GameObject main_arm;
    public GameObject v_arm;
    public GameObject thebase;
    public GameObject claw1;
    public GameObject claw2;

    public Vector3 desiredRotation1 = new Vector3();
    public Vector3 desiredRotation2 = new Vector3();
    public Vector3 desiredRotation3 = new Vector3();
    public Vector3 desiredRotation4 = new Vector3();
    // private int h, i, j, k;
    private GameObject obj1;
    private GameObject obj2;
    private GameObject obj3;
    private GameObject obj4;


    // port
    SerialPort serialPort = new SerialPort("COM3", 9600);
    private string pos1,pos2,pos3,pos4;

    void Start()
    {
        // 开启串口
        serialPort.Open();

        desiredRotation1 = main_arm.transform.localEulerAngles;
        desiredRotation2 = v_arm.transform.localEulerAngles;
        desiredRotation3 = thebase.transform.localEulerAngles;
        desiredRotation4 = claw1.transform.localEulerAngles;
        // h = 0;i = 0;j = 0;k = 0;
 
        obj1 = GameObject.Find("Main_Arm"); // 获取对象
        obj2 = GameObject.Find("V_Arm"); // 获取对象
        obj3 = GameObject.Find("Base"); // 获取对象
        obj4 = GameObject.Find("Claw"); // 获取对象
    }

    // Update is called once per frame
    void Update()
    {

        if (Input.GetKeyDown(KeyCode.Escape))
        {
            Application.Quit();
        }

        //if (Input.GetKey(KeyCode.UpArrow))
        //{
        //    i++;
        //    if(i == 2)
        //    {
        //        desiredRotation1.x += 1;
        //        i = 0;
        //    }


        //}

        //if (Input.GetKey(KeyCode.DownArrow))
        //{
        //    j++;
        //    if(j == 2)
        //    {
        //        desiredRotation1.x -= 1;
        //        j = 0;
        //    }

        //}
        ////
        //if (Input.GetKey(KeyCode.RightArrow))
        //{
        //    k++;
        //    if(k == 2)
        //    {
        //        desiredRotation2.x += 1;
        //        k = 0;
        //    }

        //}

        //if (Input.GetKey(KeyCode.LeftArrow))
        //{
        //    h++;
        //    if(h == 2)
        //    {
        //        desiredRotation2.x -= 1;
        //        h = 0;
        //    }

        //}
        desiredRotation1.x = obj1.GetComponent<Click>().value;
        desiredRotation2.x = obj2.GetComponent<Click>().value;
        desiredRotation3.y = obj3.GetComponent<Click>().value;
        desiredRotation4.z = obj4.GetComponent<Click>().value;

        main_arm.transform.localEulerAngles = desiredRotation1;
        v_arm.transform.localEulerAngles = desiredRotation2;
        thebase.transform.localEulerAngles = desiredRotation3;
        claw1.transform.localEulerAngles = desiredRotation4;
        claw2.transform.localEulerAngles = - desiredRotation4;

        if (serialPort.IsOpen)
        {
            // 发送包含四个数字的字符串
            string message = "";
            pos1 = desiredRotation1.x.ToString();
            pos2 = desiredRotation2.x.ToString();
            pos3 = desiredRotation3.y.ToString();
            pos4 = desiredRotation4.z.ToString();
            message = pos1 + " " + pos2 + " " + pos3 + " " + pos4;
            Debug.Log(message);

            serialPort.WriteLine(message);
        }

    }
    void OnDestroy()
    {
        // 关闭串口
        serialPort.Close();
    }
}
