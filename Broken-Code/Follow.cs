using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Follow : MonoBehaviour
{
    [SerializeField] GameObject objectToFollow;
    [SerializeField] private int followSpeed;
    Rigidbody2D objectToFollowPosition;
    Rigidbody2D ourObjectPosition;
    Animator animator;
    private float direction = 1;

    void Awake()
    {
        objectToFollowPosition = objectToFollow.GetComponent<Rigidbody2D>();
        ourObjectPosition = GetComponent<Rigidbody2D>();
        animator = GetComponent<Animator>();
    }

    
    void FixedUpdate()
    {
        SetFollow();
    }

    private void SetFollow()
    {
        Vector2 follow = objectToFollowPosition.position - ourObjectPosition.position;
        animator.SetFloat("Direction", direction);
        if (follow.x < -.5f)
        {
            ourObjectPosition.position += Vector2.left * Time.deltaTime * followSpeed;
            direction = -1;
        }else if (follow.x > .5f)
        {
            ourObjectPosition.position -= Vector2.left * Time.deltaTime * followSpeed;
            direction = 1;
        }else if (!animator.GetCurrentAnimatorStateInfo(0).IsName("Attack"))
        {
            animator.SetTrigger("Attack");
        }
    }
    //private void Follow()
    //{
    //    //Vector2 follow = playerController.transform.position - transform.position;
    //    Vector2 follow = playerPosition.position - rigidBody2D.position;
    //    animator.SetFloat("Direction", direction);
    //    if (follow.x < -.5)
    //    {
    //        //transform.Translate(Vector2.left * Time.deltaTime * moveSpeed);
    //        //rigidBody2D.MovePosition(Vector2.left * Time.deltaTime * moveSpeed);
    //        rigidBody2D.position += Vector2.left * Time.deltaTime * moveSpeed;
    //        direction = -1;
    //    }
    //    else if (follow.x > .5)
    //    {
    //        //transform.Translate(Vector2.right * Time.deltaTime * moveSpeed);
    //        //rigidBody2D.MovePosition(Vector2.right * Time.deltaTime * moveSpeed);
    //        rigidBody2D.position -= Vector2.left * Time.deltaTime * moveSpeed;
    //        direction = 1;
    //    }
    //    else if (!animator.GetCurrentAnimatorStateInfo(0).IsName("Attack"))
    //    {
    //        animator.SetTrigger("Attack");
    //    }
    //}

}
