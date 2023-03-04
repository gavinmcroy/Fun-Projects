using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class Enemy : MonoBehaviour
{
    [SerializeField] private int scoreForKill=10;
    [SerializeField] private int health = 100;
    [SerializeField] private int moveSpeed = 1;
    [SerializeField] TextMeshProUGUI text;
    [SerializeField] Friendly friendly;
    Animator animator;
    Movement playerController;
    GameController gameController;
    Rigidbody2D rigidBody2D;
    //Rigidbody2D friendlyPosition;
    Animator friendlyAnimator;
    //Rigidbody2D playerPosition;
    private int direction = -1;


    void Awake()
    {
        animator = GetComponent<Animator>();
        if (GameObject.FindGameObjectWithTag("Friendly") != null)
        {
            friendly = GameObject.FindGameObjectWithTag("Friendly").GetComponent<Friendly>();
            //friendlyPosition = friendly.GetComponent<Rigidbody2D>();
            friendlyAnimator = friendly.GetComponent<Animator>();
        }
        playerController = FindObjectOfType<Movement>();
        //playerPosition = playerController.GetComponent<Rigidbody2D>();
        rigidBody2D = GetComponent<Rigidbody2D>();
        gameController = FindObjectOfType<GameController>();

        animator.SetInteger("Health", health);
        text.text = health.ToString();
    }

    void FixedUpdate()
    {
        Follow();   
    }

    public void DestroyObject()
    {
        Destroy(gameObject);
    }

    public void DestroyCollision()
    {
        rigidBody2D.gravityScale = 0;
        Destroy(GetComponent<BoxCollider2D>());
    }

    public void DealDamage(int val)
    {
        RaycastHit2D rayCast = Physics2D.Raycast(rigidBody2D.position, new Vector2(direction, 0), .75f, LayerMask.GetMask("Player"));
        if (rayCast.collider == null)
        {
            return;
        }
        if (rayCast.collider == playerController.GetComponent<BoxCollider2D>())
        {
            playerController.TakeDamage(val);

        }
        if (friendly!= null)
        {
            if (rayCast.collider == friendly.GetComponent<BoxCollider2D>())
            {
                friendly.TakeDamage(val);
                Debug.Log("Friendly Damaged -" + val);
            }
        }
    }

    public void TakeDamage(int damage)
    {
        if (health > 0)
        {
            health -= damage;
            text.text = health.ToString();
            animator.SetInteger("Health", health);
        }if (health <= 0)
        {
            transform.gameObject.tag = "Dead";
            Debug.Log("Kill");
            gameController.AddScore(scoreForKill);
        }
    }

    public void SetMovementSpeed(int speed)
    {
        moveSpeed = speed;
    }

    public void SetDirection(int direction)
    {
        this.direction = direction;
    }

    private void Follow()
    {
        Vector2 follow = Movement.GetPosition() - rigidBody2D.position;
        //if (friendly.GetPosition() != null)
       // {
            if (follow.magnitude > friendly.GetPosition().magnitude && !friendlyAnimator.GetCurrentAnimatorStateInfo(0).IsName("Death"))
            {
                follow = friendly.GetPosition() - rigidBody2D.position;
            }
       // }
        animator.SetFloat("Direction", direction);
        if (follow.x < -.5)
        {
            rigidBody2D.position += Vector2.left * Time.deltaTime * moveSpeed;
            direction = -1;
        }
        else if (follow.x > .5)
        {
            rigidBody2D.position -= Vector2.left * Time.deltaTime * moveSpeed;
            direction = 1;
        }
        else if (!animator.GetCurrentAnimatorStateInfo(0).IsName("Attack"))
        {
            animator.SetTrigger("Attack");
        }
    }
}
