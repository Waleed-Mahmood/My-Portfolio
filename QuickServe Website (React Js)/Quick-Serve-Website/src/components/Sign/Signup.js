import React from 'react'
import { Checkbox, Button } from '@material-ui/core'
import { FormControlLabel } from '@material-ui/core'
import { TextField, Avatar, Grid, Paper, Typography, FormControl, FormLabel, Link, RadioGroup, Radio } from '@material-ui/core'
import './style.css'
const Signup = () => {
    const paperstyle = { padding: 20, height: '60vh', width: '50vw', margin: "0 auto", backgroundColor: '#B3E8E5', borderRadius: '40px' }
    const h2style = { margin: 0 }
    const avatarStyle = { backgroundColor: 'black' }
    const marginTop = { marginTop: 5 }
    const marginStyle = { padding: 1 }
    const borderStyle = { padding: 2, paddingBlockStart: 10 }

    return (
        <div id='signup'>
            <Grid>
                <Paper elevation={20} style={paperstyle}>
                    <Grid align='center'>
                        <Avatar style={avatarStyle} >

                        </Avatar>
                        <h2 style={h2style}>
                            Sign up
                        </h2>
                        <Typography variant='caption'>
                            Please fill this form to create the acocunt
                        </Typography>
                    </Grid>
                    <form>
                        <TextField fullWidth label='Name' placeholder="Enter your name" variant="standard" />
                        <TextField fullWidth label='Email' placeholder="Enter your email" variant="standard" />

                        <FormControl component="fieldset" style={marginTop}>
                            <FormLabel component="legend">Gender</FormLabel>
                            <RadioGroup aria-label="gender" name="gender" style={{ display: 'initial' }}>
                                <FormControlLabel value="female" control={<Radio />} label="Female" />
                                <FormControlLabel value="male" control={<Radio />} label="Male" />
                            </RadioGroup>
                        </FormControl>
                        <TextField fullWidth label='Phone Number' placeholder="Enter your phone number" variant="standard" />
                        <TextField fullWidth label='Password' placeholder="Enter your password" variant="standard" />
                        <TextField fullWidth label='Confirm Password' placeholder="Confirm your password" variant="standard" />
                        <FormControlLabel style={marginStyle}
                            control={<Checkbox name="checkedA" />}
                            label="I accept the terms and conditions."
                        />
                        <Button className='Button' type='submit' color='black' variant='contained' fullWidth>
                            Sign up
                        </Button>

                    </form>
                </Paper>
            </Grid>
        </div>
    )
}

export default Signup