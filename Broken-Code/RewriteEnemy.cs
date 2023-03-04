using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RewriteEnemy : MonoBehaviour,AIAttack
{
    [SerializeField] private int health = 100;
    [SerializeField] private int moveSpeed = 1;
    [SerializeField] private float attackRange = .75f;
    [SerializeField] private float lookRange = 10f;
    [SerializeField] float attackSpeed = 1f;
    private int direction = -1;
    Animator animator;
    Rigidbody2D rigidBody2D;
    GameController gameController;


    void Awake()
    {
        animator = GetComponent<Animator>();
        rigidBody2D = GetComponent<Rigidbody2D>();
        animator.SetInteger("Health", health);
    }

    void FixedUpdate()
    {
        
    }

    public void SetMovementSpeed(int speed)
    {
        moveSpeed = speed;
    }

    public void SetAttackSpeed()
    {
        animator.speed = attackSpeed;
    }

    public void ResetAttackSpeed()
    {
        animator.speed = 1;
    }

    public void DealDamage(int damage)
    {

    }

    public void TakeDamage(int damage)
    {

    }

    public void DestroyObject()
    {

    }

}
