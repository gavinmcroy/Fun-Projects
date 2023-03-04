using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Move : MonoBehaviour
{
    private int moveSpeed = 56;
    Rigidbody2D rigidBody2D;

    void Start()
    {
        DontDestroyOnLoad(gameObject);
        rigidBody2D = GetComponent<Rigidbody2D>();
    }

    void Update()
    {
        MoveObject();
    }

    private void MoveObject()
    {
        float horizontal = Input.GetAxisRaw("Horizontal");
        float vertical = Input.GetAxisRaw("Vertical");

        Vector2 move = new Vector2(horizontal, vertical);

        Vector2 position = rigidBody2D.position;

        position += move * (moveSpeed * Time.deltaTime);

        rigidBody2D.MovePosition(position);
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        FadeTransition.instance.StartTransition();
    }

}
