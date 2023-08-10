import React, { useEffect, useState } from 'react'
import { useParams } from 'react-router';
import './css/Movie.css';
import { MovieData } from '../components/MovieData';
import { Link } from 'react-router-dom';

function Movie() {
    const { id } = useParams();
    const [movie, setMovie] = useState();

    useEffect(() => {
        const found = MovieData.find(obj => {
            return obj.id === parseInt(id);
        });
        if (found) {
            setMovie(found);
        }
    }, []);


    return (
        <>
            <div className='movie-container'>

                <Link className='movie-goBack' to='/Movies'>
                    <span> &#8592;</span> <span>Go Back</span>
                </Link>
                {movie ? (
                    <div className='movie-wrap'>
                        <header>
                            <p className='movie-date'>Published {movie.year}</p>
                            <h1>{movie.title}</h1>
                            <div className='movie-category'>
                                <p>{movie.rating}</p>
                            </div>
                        </header>
                        <img src={"/" + movie.thumbnail} alt='cover' />
                        {/* console.log({movie.cover}); */}
                        <p className='movie-desc'>{movie.extract}</p>
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
export default Movie


