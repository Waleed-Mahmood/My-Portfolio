import { createAsyncThunk, createSlice } from '@reduxjs/toolkit';
import MovieServiceApi from '../../api/MovieServiceApi';

export const getPopularMovies = createAsyncThunk(
    'movies/getPopularMovies',
    async () => {
        const movies = await MovieServiceApi.getPopularMovies();
        return movies;
    }
);

// export const addMoviesToLocalList = (movies) => {
//     return (dispatch) => {
//         movies.forEach(movie => {
//             dispatch(addMovie(movie));
//         });
//     }
// }
// export const addMovie = createAsyncThunk(
//     'movies/addMovie',
//     async () => {
//         const movies = await MovieServiceApi.addMovie();
//         return movies;
//     }
// );

// export const updateMovie = createAsyncThunk(
//     'movies/updateMovie',
//     async () => {
//         const movies = await MovieServiceApi.updateMovie();
//         return movies;
//     }
// );

// export const deleteMovie = createAsyncThunk(
//     'movies/deleteMovie',
//     async () => {
//         const response = await MovieServiceApi.deleteMovie();
//         return response;
//     }
// );

const initialState = {
    moviesList: [],
    status: 'idle',
    movieCount: 0,
    error: null,
    isLoading: true,
};

const movieSlice = createSlice({
    name: 'movies',
    initialState,
    reducers: {
        addNewMovies: (state, action) => {
            const { movie } = action.payload;
            // Check if the movie already exists in the array
            const existingMovieIndex = state.findIndex((m) => m.id === movie.id);
            if (existingMovieIndex === -1) {
                // If the movie doesn't exist in the array, add it
                state.movieList.push(...movie);
            }
        },
    },
    extraReducers: (builder) => {
        builder
            // Fetch movie
            .addCase(getPopularMovies.pending, (state) => {
                state.isLoading = true;
                state.status = 'loading';
            })
            .addCase(getPopularMovies.fulfilled, (state, action) => {
                console.log(action);
                state.status = 'succeeded';
                state.moviesList = action.payload;
                state.isLoading = false;
                state.movieCount = action.payload.length;
            })
            .addCase(getPopularMovies.rejected, (state, action) => {
                state.status = 'failed';
                state.error = action.error.message;
            })

        // // Add movie
        // .addCase(addMovie.pending, (state) => {
        //     state.status = 'loading';
        // })
        // .addCase(addMovie.fulfilled, (state, action) => {
        //     state.status = 'succeeded';
        //     state.movies.push(action.payload);
        // })
        // .addCase(addMovie.rejected, (state, action) => {
        //     state.status = 'failed';
        //     state.error = action.payload;
        // })


        // // Update movie
        // .addCase(updateMovie.pending, (state) => {
        //     state.status = 'loading';
        // })
        // .addCase(updateMovie.fulfilled, (state, action) => {
        //     const index = state.movies.findIndex((movie) => movie.id === action.payload.id);
        //     if (index !== -1) {
        //         state.movies[index] = action.payload;
        //     }
        // })
        // .addCase(updateMovie.rejected, (state, action) => {
        //     state.status = 'failed';
        //     state.error = action.payload;
        // })


        // // Delete movie
        // .addCase(deleteMovie.pending, (state) => {
        //     state.status = 'loading';
        // })
        // .addCase(deleteMovie.fulfilled, (state, action) => {
        //     state.movies = state.movies.filter((movie) => movie.id !== action.payload);
        // })
        // .addCase(deleteMovie.rejected, (state, action) => {
        //     state.status = 'failed';
        //     state.error = action.payload;
        // });
    }
});

export default movieSlice.reducer;