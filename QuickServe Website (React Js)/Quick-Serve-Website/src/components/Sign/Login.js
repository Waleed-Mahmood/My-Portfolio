import React from 'react'
// import {Avatar, Grid, Paper, TextField,Link, Typography} from '@mui/material'
// import LockIcon from '@mui/icons-material/';
// import { Button  } from '@mui/material';
// import { Checkbox } from '@mui/material';
// import { FormControlLabel } from '@mui/material';
import { Avatar, Grid, Paper, TextField, Link, Typography } from '@material-ui/core'
import { Lock } from '@mui/icons-material'
import { Button } from '@mui/material'
import { Checkbox } from '@material-ui/core'
import { FormControlLabel } from '@material-ui/core'
import './style.css'
const Login = () => {
    const avatarStyle = { backgroundColor: 'black' }
    const paperstyle = { padding: 20, height: '50vh', width: '50vw', margin: "0 auto", backgroundColor: '#B3E8E5', borderRadius:'40px' }
    const btnStyle = { margin: '20px 0' }
    const borderStyle = { padding: 2, paddingBlockStart:10 }

    return (
        <div id='signin'>
            <Grid>
                <Paper elevation={10} style={paperstyle}>
                    <Grid align='center'>
                        <Avatar style={avatarStyle}> <Lock /></Avatar>
                        <h2>Log in</h2>
                    </Grid>
                    <TextField id="username-text" label="Username" variant="standard" placeholder='Enter username' fullWidth required></TextField>
                    <TextField id="password-text" label="Password" variant="standard" placeholder='Enter Password' fullWidth required></TextField>

                    <FormControlLabel style={{paddingBlockStart:'20px'}} control={<Checkbox defaultChecked />} label="Remember me" />
                    <p></p>
                    <Button className='Button' type='submit' color='primary' variant='contained' fullWidth>
                        log in
                    </Button>

                    <Typography style={borderStyle}>
                        <Link href="#">
                            Forgot password ?
                        </Link>

                    </Typography>
                    <Typography style={borderStyle}> Do you have account ?
                        <Link href="#" >
                            Sign up
                        </Link>

                    </Typography>


                </Paper>
            </Grid>
        </div>
    )
}

export default Login