import React, { useEffect, useState } from 'react'
import { useParams } from 'react-router';
import './css/Blog.css';
import { BlogData } from '../components/BlogData';
import { Link } from 'react-router-dom';

function Blog() {
    const { id } = useParams();
    const [blog, setBlog] = useState();

    useEffect(() => {
        const found = BlogData.find(obj => {
            return obj.id === parseInt(id);
        });
        if (found) {
            setBlog(found);
        }
    }, []);


    return (
        <>
            <div className='blog-container'>

                <Link className='blog-goBack' to='/BlogsHome'>
                    <span> &#8592;</span> <span>Go Back</span>
                </Link>
                {blog ? (
                    <div className='blog-wrap'>
                        <header>
                            <p className='blog-date'>Published {blog.createdAt}</p>
                            <h1>{blog.title}</h1>
                            <div className='blog-category'>
                                <p>{blog.category}</p>
                            </div>
                        </header>
                        <img src={"/" + blog.cover} alt='cover' />
                        {/* console.log({blog.cover}); */}
                        <p className='blog-desc'>{blog.description}</p>
                    </div>

                ) : (
                    <div className='emptyList-wrap'>
                        <img src='/empty.gif' alt='empty' />
                    </div>
                )}
            </div>
        </>
    );
}
export default Blog


