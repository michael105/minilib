#!/usr/bin/env bats

KEY='YW2N4W7UBAIAEVCT'

KEYFILE='YW2N4W7UBAIAEVCT
" WINDOW_SIZE 3
" TOTP_AUTH
48620924
62845873
18191372
38435027
50135452
'

export TOTP_SECONDS=1558265803

@test "totp: generate token" {
    run totp "$KEY"
    cat << EOF
--- output
$output
--- output
EOF

    [ "$output" = "734544" ]
}

@test "totp: token from previous offset" {
    run totp "$KEY" 30 -30
    cat << EOF
--- output
$output
--- output
EOF

    [ "$output" = "648256" ]
}

@test "totp: token from next offset" {
    run totp "$KEY" 30 30
    cat << EOF
--- output
$output
--- output
EOF

    [ "$output" = "335736" ]
}

@test "totp: read key from stdin" {
    run sh -c "echo $KEY | totp - 30 -90"
    cat << EOF
--- output
$output
--- output
EOF

    [ "$output" = "492367" ]
}
