import React from 'react'
import MovieItem from '../components/MovieItem'
import { MovieData } from '../components/MovieData'
import './css/Movies.css'
import { useParams } from 'react-router-dom';

function Movies() {
    const { searchKeyword } = useParams();

    const filteredList = searchKeyword
        ? MovieData.filter((movie) =>
            movie.title.toLowerCase().includes(searchKeyword.toLowerCase())
        )
        : MovieData.filter((i, index) => (index < 15));

    return (
        <>
            <div className='movies-container'>
                <div className='movies-header'>
                    <h1>
                        <span>“</span> Welcome Viewer<span>”</span>
                    </h1>
                    <p>
                        Stream or Download your Favorite Movies
                    </p>
                </div>
                <div className='movies-cards'>
                    <MovieItem movie={filteredList} />
                </div>
            </div>


        </>
    )
}
export default Movies