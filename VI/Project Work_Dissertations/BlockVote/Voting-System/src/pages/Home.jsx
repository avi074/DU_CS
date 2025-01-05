import { Box } from "@mui/material";
import React from "react";

const Home = () => {
    return (
        <Box className="home" display="flex" width="100%" alignItems="center" justifyContent="center">
            <Box className="wrapper">
                <Box className="glow" data-text="Glow">
                    Web3.0 BlockVote
                </Box>
                <Box className="glow-shadow" aria-hidden="true">
                    Welcome
                </Box>
            </Box>
        </Box>
    );
};

export default Home;
