import React from 'react'
import "./BlogItem.css"
import { Link } from 'react-router-dom';

export default function BlogItem({ blog }) {
    // const im = blog.cover;
    // console.log(blog[0].cover);
    return (
        blog.map(blog => (
            <div className='blogItem-wrap'>
                <img className='blogItem-cover' src={blog.cover} alt='cover' />
                <p className='blogItem-category'>{blog.category}</p>
                <h3>{blog.title}</h3>
                <p className='blogItem-desc'>{blog.description}</p>
                <footer>
                    <div className='blogItem-author'>
                        <img src={blog.authorAvatar} alt='avatar' />
                        <div>
                            <h6>{blog.authorName}</h6>
                            <p>{blog.createdAt}</p>
                        </div>
                    </div>
                    <Link className='blogItem-link' to={`/Blog/${blog.id}`}>
                        Read ➝
                    </Link>
                </footer>
            </div>
        ))
    )
}
