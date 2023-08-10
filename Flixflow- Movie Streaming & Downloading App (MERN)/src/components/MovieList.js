import React, { useEffect, useState } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { getPopularMovies } from '../features/movies/movieSlice';
import { MovieData } from './MovieData';

function MovieList() {
    // const moviesList = useSelector(store => store.movies.moviesList);
    // const status = useSelector(store => store.movies.status);
    // const error = useSelector(store => store.movies.error);
    // const isLoading = useSelector(store => store.movies.isLoading);
    // const movieCount = useSelector(store => store.movies.movieCount);

    const dispatch = useDispatch();
    // const [movies, setMovies] = useState([]);
    const { moviesList, movieCount, status, error, isLoading } = useSelector(store => store.movies);
    const filteredList = MovieData.filter((i, index) => (index < 3));

    useEffect(() => {
        dispatch(getPopularMovies());
    }, [dispatch]);

    if (status === 'loading') {
        return <div>Loading...</div>;
    }

    if (status === 'failed') {
        return <div>Error: {error}</div>;
    }

    const existingMovies = MovieData.map(movie => movie.id);
    // const existingMovies = moviesList.map(movie => movie.id);
    moviesList.forEach(movie => {
        if (!existingMovies.includes(movie.id)) {
            MovieData.push(movie);
        }
    })



    return (
        <>
            <div>
                <h1>Popular Movies</h1>
                <ul>
                    {moviesList.map(movie => (
                        <li key={movie.id}>{movie.title}</li>
                    ))}
                </ul>
                <h1>status: {status}</h1>
                <h1>count: {movieCount}</h1>
                <h1>Loading: {isLoading}</h1>
                <h1>error: {error}</h1>


                {/* <ul>
                    {
                        .map((i, movie) => {
                        <>
                            <li key={movie.title}>
                                {movie.title}
                            </li>
                            
                        </>

                    })
                    }
                </ul> */}

                <ul>
                    {
                        filteredList.map((movie) => (
                            <li>
                                {movie.title}
                                <img src={movie.thumbnail} style={{ width: movie.thumbnail_width, height: movie.thumbnail_height }} alt="poster"></img>
                            </li>
                        ))
                    }
                </ul>


            </div>

        </>

    )
}

export default MovieList;