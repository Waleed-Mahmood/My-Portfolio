// import SearchBar from '../../components/Home/SearchBar';
import { BlogData } from '../components/BlogData';
import BlogItem from '../components/BlogItem';
import './css/BlogsHome.css'

function BlogsHome() {
    return (
        <>
            <div className='bloghome-container'>
                <div className='bloghome-header'>
                    <h2>Inc. This Morning</h2>
                    <h1>
                        <span>“</span> Blog <span>”</span>
                    </h1>
                    <p>
                        Awesome Place to Make Oneself <br /> Productive & Entertained Through
                        Daily Updates.
                    </p>
                </div>
                <div className='bloghome-cards'>
                    <BlogItem blog={BlogData} />
                </div>
            </div>


        </>
    )
}
export default BlogsHome