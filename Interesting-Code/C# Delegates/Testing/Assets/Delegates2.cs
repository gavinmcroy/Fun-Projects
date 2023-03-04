using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Delegates2 : MonoBehaviour
{
    public class Worker
    {
        List<string> WorkCompletedFor = new List<string>();

        public void DoSomething(string managerName, Action myDelegate)
        {
            WorkCompletedFor.Add(managerName);
            myDelegate();
        }
    }

    public class Manager
    {
        private Worker _myWorker = new Worker();

        public void PieceOfWork1()
        {
            Debug.Log("Its work");
        }

        public void PieceofWork2()
        {
            Debug.Log("its more work!");
        }

        public void DoWork()
        {
            _myWorker.DoSomething("Manager1", PieceOfWork1);
            _myWorker.DoSomething("Manager1", PieceofWork2);
        }
    }
}