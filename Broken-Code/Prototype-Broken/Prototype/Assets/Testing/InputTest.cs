using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class InputTest : MonoBehaviour
{
    // Start is called before the first frame update
    void Awake()
    {
       Screen.SetResolution(1920,1080,true); 
    }

    // Update is called once per frame
    void Update()
    {
        var keyboard = Keyboard.current;
        if (keyboard == null)
        {
            Debug.Log("Error");
        }
        if (keyboard.spaceKey.isPressed)
        {
            Debug.Log("It works");
        }
    }
}
