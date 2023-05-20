import dash
from dash.dependencies import Input, Output, State
from dash import html, dcc
import random

app = dash.Dash(__name__)


app.layout = html.Div([
    html.Div([
        html.H3('Extend a specific trace'),
        dcc.Dropdown(
            id='trace-selection',
            options=[
                {'label': 'extend trace 0', 'value': 0},
                {'label': 'extend trace 1', 'value': 1},
            ],
            value=0
        ),
        dcc.Graph(
            id='graph-extendable',
            figure=dict(
                data=[{'x': [0, 1, 2, 3, 4],
                       'y': [0, .5, 1, .5, 0],
                       'mode':'lines+markers'
                       },
                      {'x': [0, 1, 2, 3, 4],
                       'y': [1, 1, 1, 1, 1],
                       'mode':'lines+markers'
                       }],
            )
        ),
    ]),
    html.Div([
        html.H3('Extend multiple traces at once'),
        dcc.Graph(
            id='graph-extendable-2',
            figure=dict(
                data=[{'x': [0, 1, 2, 3, 4],
                       'y': [0, .5, 1, .5, 0],
                       'mode':'lines+markers'
                       },
                      {'x': [0],
                       'y': [0],
                       'mode':'lines'
                       },
                      {'x': [0, .1, .2, .3, .4],
                       'y': [0, 0, 0, 0, 0],
                       'mode':'markers'
                       }],
            )
        ),
    ]),
    dcc.Interval(
        id='interval-graph-update',
        interval=1000,
        n_intervals=0),
])


@app.callback(Output('graph-extendable', 'extendData'),
              [Input('interval-graph-update', 'n_intervals')],
              [State('graph-extendable', 'figure'),
               State('trace-selection', 'value')])
def update_extend_traces_traceselect(n_intervals, existing, trace_selection):
    x_new = existing['data'][trace_selection]['x'][-1] + 1
    y_new = random.random()
    return dict(x=[[x_new]], y=[[y_new]]), [trace_selection]


@app.callback(Output('graph-extendable-2', 'extendData'),
              [Input('interval-graph-update', 'n_intervals')],
              [State('graph-extendable-2', 'figure')])
def update_extend_traces_simult(n_intervals, existing):
    return (dict(x=[
        [existing['data'][0]['x'][-1] + 1],
        [existing['data'][1]['x'][-1] - .5, existing['data'][1]['x'][-1] + 1],
        [existing['data'][2]['x'][-1] + .1]
    ],
        y=[
        [random.random()],
        [0, random.random()],
        [random.random()]
    ]),
        [0, 1, 2]
    )


if __name__ == '__main__':
    app.run_server(debug=True)
    