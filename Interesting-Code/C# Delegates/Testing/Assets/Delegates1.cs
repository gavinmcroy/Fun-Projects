using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Delegates1 : MonoBehaviour
{
    delegate void RobotAction();

    private RobotAction _myRobotAction;
    void Start()
    {
        _myRobotAction = RobotWalk;
    }

    
    void Update()
    {
        _myRobotAction();
    }

    void DoRobotWalk()
    {
        _myRobotAction = RobotWalk;
    }
    
    void RobotWalk()
    {
        Debug.Log("Robot Walking");
    }

    void DoRobotRun()
    {
        _myRobotAction = RobotRun;
    }

    void RobotRun()
    {
        Debug.Log("Robot Running");
    }
}
