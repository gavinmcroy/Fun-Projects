using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Friendly : MonoBehaviour
{
    [SerializeField] private int moveSpeed = 1;
    [SerializeField] private int health = 20;
    [SerializeField] private float attackRange = .75f;
    [SerializeField] float attackSpeed = 1f;
    private float direction = -1;
    Rigidbody2D rigidBody2D;
    Rigidbody2D enemyPos;
    Enemy enemy;
    Animator animator;
    Animator enemyAnimator;

    private void Awake()
    {
        enemy = GameObject.FindGameObjectWithTag("Enemy").GetComponent<Enemy>();
        animator = GetComponent<Animator>();
        enemyAnimator = enemy.GetComponent<Animator>();
        enemyPos = enemy.GetComponent<Rigidbody2D>();
        rigidBody2D = GetComponent<Rigidbody2D>();
        animator.SetInteger("Health", health);
    }

    void FixedUpdate()
    {
        FollowAndAttackEnemy();
    }

    public void SetMovementSpeed(int speed)
    {
        moveSpeed = speed;
    }

    public void SetAttackSpeed()
    {
        animator.speed = attackSpeed;
    }

    public Vector2 GetPosition()
    {
        return rigidBody2D.position;
    }

    public void ResetAttackSpeed()
    {
        animator.speed = 1;
    }

    public void DealDamage(int damage)
    {
        RaycastHit2D rayCast = Physics2D.Raycast(rigidBody2D.position, new Vector2(direction, 0), attackRange, LayerMask.GetMask("Hostile"));
        if (rayCast.collider != null)
        {
            enemy.TakeDamage(damage);
        }
    }


    public void TakeDamage(int damage)
    {
        if (health > 0)
        {
            health -= damage;
            animator.SetInteger("Health", health);
        }
        if (health <= 0)
        {
            Debug.Log("Killed Friendly");
        }
    }

    //---Missing From Rewrite
    public void DestroyObject()
    {
        Destroy(gameObject, 3);
    }

    //---Missing From Rewrite
    public void DestroyCollision()
    {
        rigidBody2D.gravityScale = 0;
        Destroy(GetComponent<BoxCollider2D>());
    }

    private void FollowAndAttackEnemy()
    {
        if (enemyAnimator.GetCurrentAnimatorStateInfo(0).IsName("Death"))
        {
            enemy = GameObject.FindGameObjectWithTag("Enemy").GetComponent<Enemy>();
            enemyAnimator = enemy.GetComponent<Animator>();
            enemyPos = enemy.GetComponent<Rigidbody2D>();
        }
        Vector2 follow = enemyPos.position - rigidBody2D.position;
        animator.SetFloat("Direction",direction);
        if (follow.x < -.5)
        {
            rigidBody2D.position += Vector2.left * Time.deltaTime * moveSpeed;
            direction = -1;
        }else if (follow.x > .5)
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
